#include "main.h"

/**
 * _atoi - convert a string to an integer.
 * @s: pointer to the string to be converted
 *
 * Return: converted int
 */

int _atoi(char *s)
{
	int i;
	unsigned int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] < '0' || s[i] > '9')
	{
		if (s[i] == '\0')
			return (0);
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num * sign);
}
