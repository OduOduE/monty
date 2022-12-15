#include "monty.h"

/**
 * instruction_push - push an element into the stack
 * @stack: double pointer to first node
 * @line_number: value of new node
 * Return: nothing
 */
void instuction_push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
 * instruction_pall - prints all values on the stack from top
 * @stack: double pointer to first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	UNUSED(line_number);
	while (element)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
