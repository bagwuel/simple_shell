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
	{
		perror("Usage: ./shell\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, prompt, strlen(prompt));
		input = _prompt();
		if (input == NULL)
			exit(EXIT_FAILURE);
		if (*input == '\n')
			continue;
		command = _tokenizer(input);
		if (command == NULL)
		{
			free(input);
			continue;
		}
		comm = strdup(command[0]);
		if (command[0] == NULL)
		{
			write(1, comm, strlen(comm));
			write(1, ": command not found\n", 20);
			continue;
		}
		if (_forkexec(command, av[0]) == 1)
		{
			free(input);
			continue;
		}
	}
	return (0);
}
