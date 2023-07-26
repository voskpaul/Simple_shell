#include "shell.h"

/**
 * read_line - for the string input
 * @i_eof: to return value of function getline
 * Return: string input.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
