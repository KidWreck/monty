#include "monty.h"


/**
 * add_st - Adds a node to stack.
 * @n: Pointer new node.
 * @ln: line number.
 */
void add_st(stack_t **n, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (n == NULL || *n == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n;
		return;
	}
	t = head;
	head = *n;
	head->next = t;
	t->prev = head;
}


/**
 * print_st - prints node.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void print_st(stack_t **st, unsigned int ln)
{
	stack_t *t;

	(void) ln;
	if (st == NULL)
		exit(EXIT_FAILURE);
	t = *st;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * pop_fog - delete fog.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void pop_fog(stack_t **st, unsigned int ln)
{
	stack_t *t;

	if (st == NULL || *st == NULL)
		err_1(7, ln);

	t = *st;
	*st = t->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(t);
}

/**
 * print_fog - Prints fog.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void print_fog(stack_t **st, unsigned int ln)
{
	if (st == NULL || *st == NULL)
		err_1(6, ln);
	printf("%d\n", (*st)->n);
}
