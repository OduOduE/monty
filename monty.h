#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define TRUE 1
#define FALSE 0
#define DELIMS "\n \t\r"

/**
 * struct stack_s -doubly linked list representation of a stack (or queue)
 * @n: integer element
 * @prev: points to previous element of stack or queue
 * @next: points to next element of stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, FIFO, LIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s -opcode and its function
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

/**
 * struct glob_s - useful global variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to instruction struct
 */
typedef struct glob_s
{
	stack_t **top;
	instruction_t **ops;
} glob_t;

extern glob_t glob;

/* monty.c */
void stack_init(stack_t **head);
void free_all(void);

/* helper1.c */
int process_file(char *filename, stack_t **stack);

/* helper2.c */
void delegate_op(stack_t **stack, char *op, unsigned int line_number);

/* instruction1.c */
void instruction_push(stack_t **stack, unsigned int line_number);
void instruction_pop(stack_t **stack, unsigned int line_number);
void instruction_pint(stack_t **stack, unsigned int line_number);
void instruction_pall(stack_t **stack, unsigned int line_number);
void instruction_swap(stack_t **stack, unsigned int line_number);

/* instruction2.c */
void instruction_add(stack_t **stack, unsigned int line_number);
void instruction_nop(stack_t **stack, unsigned int line_number);
void instruction_sub(stack_t **stack, unsigned int line_number);
void instruction_div(stack_t **stack, unsigned int line_number);
void instruction_mul(stack_t **stack, unsigned int line_number);

/* instruction3.c */
void instruction_mod(stack_t **stack, unsigned int line_number);
void instruction_pchar(stack_t **stack, unsigned int line_number);
void instruction_pstr(stack_t **stack, unsigned int line_number);
void instruction_rotl(stack_t **stack, unsigned int line_number);
void instruction_rotr(stack_t **stack, unsigned int line_number);

/* _strtol.c */
int is_leading_digit(char ascii_char);
int _strtol(char *num_string, unsigned int line_number);

#endif /* MONTY_H */
