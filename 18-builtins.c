#include "main.h"

/**
 * is_builtin_cmd - short description
 * @tokens: array of commands
 *
 * Return: 1 if success 0 if failure
 */

int is_builtin_cmd(char **tokens)
{
	int i = 0;
	const struct inbuilt commands[] = {
		{"env", _env_cmd},
		{"exit", _exit_cmd},
		{NULL, NULL}
	};

	if (tokens == NULL)
		return (0);
	if (tokens[0] == NULL)
		return (0);
	while (commands[i].name != NULL)
	{
		if (strcmp(tokens[0], commands[i].name) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_builtin - short description
 * @tokens: command array
 *
 * Return: 1 if success 0 if failure
 */

int handle_builtin(char **tokens)
{
	int i = 0;
	const struct inbuilt commands[] = {
		{"env", _env_cmd},
		{"exit", _exit_cmd},
		{NULL, NULL}
	};

	if (tokens == NULL)
		return (0);
	if (tokens[0] == NULL)
		return (0);
	while (commands[i].name != NULL)
	{
		if (strcmp(tokens[0], commands[i].name) == 0)
			return (commands[i].function(tokens));
		i++;
	}
	return (0);
}
