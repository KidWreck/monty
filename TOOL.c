#include "monty.h"

/**
 * open_f - open file
 * @fn: file name
 */
void open_f(char *fn)
{
	FILE *fd = fopen(fn, "r");

	if (fn == NULL || fd == NULL)
		err_1(2, fn);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - read file
 * @fd: file descriptor
 */
void read_f(FILE *fd)
{
	int ln, klam = 0;
	char *buf = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buf, &len, fd) != -1; ln++)
	{
		klam = sep_(buf, ln, klam);
	}
	free(buf);
}


/**
 * sup_ - Separates into tokens
 * @buf: buffer
 * @ln: line number
 * @klam: format. If 0 nodes as a stack , if 1 nodes as a queue.
 * Return: 0 if stack , 1 if queue.
 */

int sup_(char *buf, int ln, int klam)
{
	char *op, *v;
	const char *dlm = "\n ";

	if (buf == NULL)
		err_1(4);

	op = strtok(buf, dlm);
	if (op == NULL)
		return (klam);
	v = strtok(NULL, dlm);

	if (strcmp(op, "STACK") == 0)
		return (0);
	if (strcmp(op, "QUEUE") == 0)
		return (1);

	find_func(op, v, ln, klam);
	return (klam);
}

/**
 * find_func - find function.
 * @op: opcode
 * @v: argument
 * @klam: format. If 0 node as a stack , if 1 node as a queue.
 * @ln: line number
 */
void find_func(char *op, char *v, int ln, int klam)
{
	int i, j;

	instruction_t my_func[] = {
		{"push", add_st},
		{"pall", print_st},
		{"pint", print_fog},
		{"pop", pop_fog},
		{"nop", nop_},
		{"swap", swap_},
		{"add", add_},
		{"sub", sub_},
		{"div", div_},
		{"mul", mul_},
		{"mod", mod_},
		{"pchar", print_c},
		{"pstr", print_s},
		{"rotl", rot_t7t},
		{"rotr", rot_fog},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;

	for (j = 1, i = 0; my_func[i].opcode != NULL; i++)
	{
		if (strcmp(op, my_func[i].opcode) == 0)
		{
			call_func(my_func[i].f, op, v, ln, klam);
			j = 0;
		}
	}
	if (j == 1)
		err_1(3, ln, op);
}


/**
 * call_func - Call function.
 * @func: Pointer to function.
 * @op: opcode.
 * @v: value.
 * @ln: line numeber.
 * @klam: Format. If 0 node as a stack , if 1 node as a queue.
 */
void call_func(my_op func, char *op, char *v, int ln, int klam)
{
	stack_t *node;
	int i, j = 1;

	if (strcmp(op, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			j = -1;
		}
		if (v == NULL)
			err_1(5, ln);
		for (i = 0; v[i] != '\0'; i++)
		{
			if (isdigit(v[i]) == 0)
				err_1(5, ln);
		}
		node = my_node(atoi(v) * j);
		if (klam == 0)
			func(&node, ln);
		if (klam == 1)
			add_q(&node, ln);
	}
	else
		func(&head, ln);
}
