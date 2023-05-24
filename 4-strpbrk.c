#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: string to be searched
 * @accept: string whose bytes is to be searched
 *
 * Return: pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, const char *accept)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
