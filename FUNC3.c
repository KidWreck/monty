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
