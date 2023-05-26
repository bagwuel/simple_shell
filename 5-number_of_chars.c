#include "main.h"

/**
 * num_of_chars - returns the number of chars in a number
 * @num: number to be counted
 *
 * Return: the number of the chars
 */
int num_of_chars(size_t num)
{
	int i = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}

	return (i);
}
