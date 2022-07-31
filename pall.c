#include "monty.h"

/**
 * pall - print stack
 * @stack: pointer to the pointer of the stack header
 * @line_number: used to pass arguments
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
