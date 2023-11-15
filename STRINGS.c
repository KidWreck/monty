#include "monty.h"

/**
 * print_c - Prints ASCII.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void print_c(stack_t **s, unsigned int ln)
{
	int a;

	if (st == NULL || *s == NULL)
		err_2(11, ln);

	a = (*st)->n;
	if (a < 0 || a > 127)
		err_2(10, ln);
	printf("%c\n", a);
}

/**
 * print_s - Prints string.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void print_s(stack_t **st, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *t;

	if (st == NULL || *st == NULL)
	{
		printf("\n");
		return;
	}

	t = *st;
	while (t != NULL)
	{
		a = t->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		t = t->next;
	}
	printf("\n");
}

/**
 * rot_t7t - Rotates to the bottom.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void rot_t7t(stack_t **st, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	t = *st;
	while (t->next != NULL)
		t = t->next;

	t->next = *st;
	(*st)->prev = t;
	*st = (*st)->next;
	(*st)->prev->next = NULL;
	(*st)->prev = NULL;
}


/**
 * rot_fog - Rotates to the top.
 * @st: Pointer to stack.
 * @ln: line number.
 */
void rot_fog(stack_t **st, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	t = *st;

	while (t->next != NULL)
		t = t->next;

	t->next = *s;
	t->prev->next = NULL;
	t->prev = NULL;
	(*st)->prev = t;
	(*st) = t;
}
