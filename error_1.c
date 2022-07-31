#include "monty.h"

/**
 * usage_error - usage_error
 *
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - usage_error
 * @file: the filename
 *
 */
void file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - usage_error
 * @line_number: line number
 * @opcode: opcode
 *
 */
void instruction_error(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - usage_error
 *
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
