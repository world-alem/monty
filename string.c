#include "monty.h"

/**
 * ltrim - left trim whitespace
 * @str: the string to be trimmed
 *
 * Return: the trimmed string
 */
char *ltrim(char *str)
{
	while (isspace(*str))
		str++;
	return (str);
}

/**
 * rtrim - right trim whitespace
 * @str: the string to be trimmed
 *
 * Return: the trimmed string
 */
char *rtrim(char *str)
{
	char *back = str + strlen(str);

	while (isspace(*--back))
		;
	*(back + 1) = '\0';
	return (str);
}

/**
 * trim - trim whitespace
 * @str: the string to be trimmed
 *
 * Return: the trimmed
 */
char *trim(char *str)
{
	return (rtrim(ltrim(str)));
}

/**
 * get_args - split line into opcode and argument
 * @line: the string
 *
 * Return: array of arguments
 */
char **get_args(char *line)
{
	char **array = malloc(strlen(line) + 1);

	array[0] = strtok(line, " ");
	array[1] = strtok(NULL, " ");

	return (array);
}

/**
 * is_numeric - check if string is integer
 * @str: the string
 *
 * Return: 0 - True. 1 - False
 */
int is_numeric(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	return (1);
}
