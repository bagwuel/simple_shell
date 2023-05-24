#include "main.h"

/**
 * main - shell program
 * @ac: size of argument array
 * @av: argument array
 *
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	char *prompt = "#cisfun$ ";
	char *input, *comm;
	char **command;

	if (ac != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, prompt, _strlen(prompt));
		input = _prompt();
		if (input == NULL)
			exit(EXIT_FAILURE);
		if (*input == '\n')
			continue;
		command = malloc(sizeof(char *) * 2);
		if (command == NULL)
		{
			free(input);
			continue;
		}
		command[0] = strtok(input, "\0");
		command[1] = NULL;
		if (command == NULL)
		{
			free(command);
			free(input);
			continue;
		}
		comm = _strdup(command[0]);
		if (command[0] == NULL)
		{
			write(1, comm, _strlen(comm));
			write(1, ": command not found\n", 20);
			free(input);
			continue;
		}
		if (_forkexec(command, av[0]) == 1)
		{
			free(input);
			continue;
		}
		free(input);
	}
	return (0);
}
