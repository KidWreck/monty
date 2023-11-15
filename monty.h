#ifndef MONTY_H
#define MONTY_H

#define _GNU_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*my_op)(stack_t **, unsigned int);


/*ERROR.c*/
void err_1(int err, ...)
void err_2(int err, ...)

/*STRINGS.c*/
void print_c(stack_t **, unsigned int);
void print_s(stack_t **, unsigned int);
void rot_t7t(stack_t **, unsigned int);
void rot_fog(stack_t **, unsigned int);

/*FUNC.c*/
void print_st(stack_t **, unsigned int);
void add_st(stack_t **, unsigned int);
void print_fog(stack_t **, unsigned int);
void pop_fog(stack_t **, unsigned int);

void nop_(stack_t **, unsigned int);
void swap_(stack_t **, unsigned int);
void add_(stack_t **, unsigned int);
void sub_(stack_t **, unsigned int);
void div_(stack_t **, unsigned int);

void mul_(stack_t **, unsigned int);
void mod_(stack_t **, unsigned int);


/************************************/
/*file operations*/
void open_f(char *);
int parse_line(char *, int, int);
void read_f(FILE *);
int len_c(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *my_node(int n);
void free_(void);

void add_q(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);




/*Math operations with nodes*/




#endif
