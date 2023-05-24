#include "main.h"

/**
 * _strtok - breaks a string into tokens of words
 * @str: string to be broken
 * @delim: delimiters
 *
 * Return: pointer to the next token on success, NULL on failure
 */

char *_strtok(char *str, const char *delim)
{
	static char *next_tok;
	char *tok_start;
	unsigned int n;

	if (!str && !next_tok)
		return (NULL);
	if (str == NULL)
		str = next_tok;
	n = _strspn(str, delim);
	str += n;
	if (*str == '\0')
		return (NULL);
	tok_start = str;
	str = _strpbrk(str, delim);
	if (str == NULL)
	{
		next_tok = _strchr(tok_start, '\0');
	}
	else
	{
		*str = '\0';
		next_tok = str + 1;
	}
	return (tok_start);
}
