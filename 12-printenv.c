#include "main.h"

/**
 * _print_env - prints environment variable
 *
 * Return: returns (0)
 */
int _print_env(void)
{
	unsigned int i = 0;

	while (__environ[i])
	{
		write(STDOUT_FILENO, __environ[i], strlen(__environ[i]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
		i++;
	}
	return (0);
}
