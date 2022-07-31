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
