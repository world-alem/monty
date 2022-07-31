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

	if (argc != 2)
		usage_error();

	file = fopen(argv[1], "r");

	if (file == NULL)
		file_error(argv[1]);

	line = malloc(MAX_BUFFER);
	line_number = 1;

	if (line == NULL)
		malloc_error();

	while (fgets(line, MAX_BUFFER, file))
	{
		char *temp = trim(line);

		printf("%s\n", temp);
		line_number++;
	}

	free(line);
	fclose(file);
	return (0);
}
