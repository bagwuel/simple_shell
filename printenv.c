#include "main.h"

/**
 * _printenv - prints the environment variables
 * @env: environment variables of a program
 */

void _printenv(char **env)
{
	int i = 0, j;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			_putchar(env[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
