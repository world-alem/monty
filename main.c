#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int line_number;
	char *line;
	instruction_t *opcodes;
	stack_t *stack;

	if (argc != 2)
		usage_error();

	file = fopen(argv[1], "r");

	if (file == NULL)
		file_error(argv[1]);

	/* initialize opcodes and stack */
	stack = NULL;
	opcodes = generate_opcodes();

	line = malloc(MAX_BUFFER);
	line_number = 1;

	if (line == NULL)
		malloc_error();

	while (fgets(line, MAX_BUFFER, file))
	{
		char *temp = trim(line);

		if (strlen(temp) > 0)
		{
			char **arr = get_args(temp);

			run_codes(&stack, opcodes, arr[0], arr[1], line_number);
		}
		line_number++;
	}

	free(line);
	fclose(file);
	return (0);
}
