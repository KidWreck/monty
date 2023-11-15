#include "monty.h"

/**
 * mul_ - mul node.
 * @stack: Pointer to stack.
 * @ln: line number.
 */
void mul_(stack_t **st, unsigned int ln)
{
	int res;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		err_1(8, ln, "mul");

	(*st) = (*st)->next;
	res = (*st)->n * (*st)->prev->n;
	(*st)->n = res;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * mod_ - mod node.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void mod_(stack_t **st, unsigned int ln)
{
	int res;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
    err_1(8, ln, "mod");
  
	if ((*st)->n == 0)
		err_2(9, ln);
	(*st) = (*st)->next;
	res = (*st)->n % (*st)->prev->n;
	(*st)->n = res;
	free((*st)->prev);
	(*st)->prev = NULL;
}

/**
 * my_node - Create node.
 * @n: Number.
 * Return: pointer or NULL.
 */
stack_t *my_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Free nodes.
 */
void free_nodes(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * add_q - Add node queue.
 * @node: new node.
 * @ln: line number.
 */
void add_q(stack_t **node, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	t = head;
	while (t->next != NULL)
		t = t->next;

	t->next = *node;
	(*node)->prev = t;

}
