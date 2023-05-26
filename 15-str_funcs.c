#include "main.h"

/**
 * _strrev - reverses a string
 * @s: the string
 */

void _strrev(char *s)
{
	int i = 0, len = 0;
	char tmp;

	while (s[len] != '\0')
		len++;
	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
}

/**
 * _itoa - converts a number to a string
 * @num: number to be convert
 *
 * Return: the converted integer
 */
char *_itoa(size_t num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	str[i] = '\0';
	_strrev(str);
	return (str);
}
