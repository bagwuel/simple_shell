#include "main.h"

/**
 * _env_cmd - prints the environment variables
 * @tokens: pointer array of commands
 *
 * Return: 0 for failure 1 for Sucess
 */

int _env_cmd(__attribute((unused)) char **tokens)
{
	int i = 0;

	while (__environ[i])
	{
		write(STDOUT_FILENO, __environ[i], strlen(__environ[i]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
		i++;
	}
	return (i);
}
