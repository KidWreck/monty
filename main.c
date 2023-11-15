#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg values
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_();
	return (0);
}
