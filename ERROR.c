#include "monty.h"

/**
 * err_1 - Prints error.
 * @err: error codes:
 * (1) => only one file.
 * (2) => if not a file.
 * (3) => invaild instruction.
 * (4) => no malloc.
 * (5) => if not int.
 * (6) => empty for pint.
 * (7) => empty for pop.
 * (8) => stack is short.
 */
void err_1(int err, ...)
{
	va_list arg;
	char *op;
	int ln;

	va_start(arg, err);
	switch (err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			ln = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_2 - Print errors.
 * @err: error codes:
 * (9) => Division by zero.
 * (10) ~> if not ASCII.
 * (11) ~> Stack is empty.
 */
void err_2(int err, ...)
{
	va_list arg;
	int ln;

	va_start(arg, err);
	ln = va_arg(arg, int);
	switch (err)
	{
    case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
