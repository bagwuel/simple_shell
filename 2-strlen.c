#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: pointer to string whose length is to be returned
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
