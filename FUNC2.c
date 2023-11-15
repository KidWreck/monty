#include "monty.h"

/**
 * nop_ - Do nothing.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void nop_(stack_t **st, unsigned int ln)
{
	(void)st;
	(void)ln;
}


/**
 * swap_ - Swaps top two nodes.
 * @stack: Pointer to stack.
 * @ln: line number.
 */
void swap_(stack_t **st, unsigned int ln)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		err_1(8, ln, "swap");
	t = (*st)->next;
	(*st)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *st;
	t->next = *st;
	(*st)->prev = t;
	t->prev = NULL;
	*st = t;
}

/**
 * add_ - Add node.
 * @stack: Pointer to stack.
 * @ln: line number.
 */
void add_(stack_t **st, unsigned int ln)
{
	int res;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		err_1(8, ln, "add");

	(*st) = (*st)->next;
	res = (*st)->n + (*st)->prev->n;
	(*st)->n = res;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * sub_ - Sub node.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void sub_(stack_t **st, unsigned int ln)
{
	int res;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
    err_1(8, ln, "sub");
  
	(*st) = (*st)->next;
	res = (*st)->n - (*st)->prev->n;
	(*st)->n = res;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * div_ - div node.
 * @stack: Pointer to stack.
 * @ln: line number.
 */
void div_(stack_t **st, unsigned int ln)
{
	int res;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		err_1(8, ln, "div");

	if ((*st)->n == 0)
		err_2(9, line_number);
	(*st) = (*st)->next;
	res = (*st)->n / (*st)->prev->n;
	(*st)->n = res;
	free((*st)->prev);
	(*st)->prev = NULL;
}
