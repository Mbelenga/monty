#include "monty.h"

/**
 * push - pushes an element onto the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all stack values
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
