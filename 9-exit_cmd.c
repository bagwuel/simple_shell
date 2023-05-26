#include "main.h"

/**
 * _exit_cmd - builtin exit command
 * @tokens: pointer to array of commands
 *
 * Return: 0 if failure 1 if sucess
 */
int _exit_cmd(char **tokens)
{
	if (tokens[1] != NULL)
		exit(atoi(tokens[1]));
	return (EXIT_CODE);
}
