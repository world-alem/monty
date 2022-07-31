#include "monty.h"

/**
 * push - push onto the stack
 * @stack: pointer to the pointer of the stack header
 * @line_number: used to pass arguments
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *node = (stack_t *)malloc(sizeof(stack_t));

	if (node == NULL)
		malloc_error();

	node->n = line_number;

	if (head == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
		node->next = head;
		node->prev = NULL;
		head->prev = node;
		*stack = node;
	}
}
