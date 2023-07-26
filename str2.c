#include "shell.h"

/**
 * _strdup - to duplicate str in memory heap.
 * @s: for char pointer str type.
 * Return: str duplicated.
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - returns length of string.
 * @s: char pointer type.
 * Return: 0 always.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - for comparing strings chars.
 * @str: string input.
 * @delim: delimiter
 * Return: 0 if not, 1 if are equals,
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - to split string in some delim.
 * @str: string input.
 * @delim: delimiter
 * Return: splited string.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*to store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*to store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*breaking loop finding next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - to define string passed if it's a number.
 * @s: for string input.
 * Return: 0 in other case, 1 if string is a number
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
