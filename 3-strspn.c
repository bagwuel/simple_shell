#include "main.h"

/**
 * _str_chr - locates a character in a string.
 * @s: string to be searched
 * @c: character to be searched for
 *
 * Return: pointer to the first occurrence of the character c
 * if found, 0 otherwise.
 */

int _str_chr(const char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: main string
 * @accept: substring
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, const char *accept)
{
	unsigned int i = 0;

	while (s[i])
	{
		if (!_str_chr(accept, s[i]))
			return (i);
		i++;
	}
	return (i);
}
