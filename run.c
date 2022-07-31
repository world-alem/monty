#include "monty.h"

/**
 * run_codes - process the opcode and argument passed
 * @stack: the stack
 * @opcodes: the opcodes
 * @opcode: the current opcode command
 * @arg: the argument passed
 * @line_number: the line number of the command
 *
 */
void run_codes(
	stack_t **stack,
	instruction_t *opcodes,
	char *opcode,
	char *arg,
	unsigned int line_number
)
{
	int i;
	int num = 0; /* number to be pushed */
	int known = 0;

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
			arg_error(line_number);
		else if (is_numeric(arg) == 0)
			arg_error(line_number);
		else
			num = atoi(arg);
	}

	for (i = 0; i < OPCODE_COUNT; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, num);
			known = 1;
			break;
		}
	}

	if (known == 0)
		instruction_error(line_number, opcode);
}

/**
 * generate_opcodes - generate opcodes
 *
 * Return: instruction_t**
 */
instruction_t *generate_opcodes()
{
	int i = 0;
	size_t array_size = sizeof(instruction_t) * (OPCODE_COUNT + 1);
	instruction_t *opcodes = (instruction_t *)malloc(array_size);

	if (opcodes == NULL)
		malloc_error();

	opcodes[i].opcode = "push";
	opcodes[i].f = &push;
	i++;

	opcodes[i].opcode = "pall";
	opcodes[i].f = &pall;
	i++;

	opcodes[i].opcode = NULL;
	opcodes[i].f = NULL;

	return (opcodes);
}
