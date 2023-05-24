#include "main.h"

/**
 * main - shell program
 * @ac: size of argument array
 * @av: argument array
 * @env: environment variables
 *
 * Return: 0 on success
 */

int main(int ac, char *av[], char **env)
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
			write(1, prompt, _strlen(prompt));
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
		if (_strcmp(command[0], "exit") == 0)
			f_exit(command[1]);
		if (_strcmp(command[0], "env") == 0)
			_printenv(env);
		comm = _strdup(command[0]);
		if (access(command[0], X_OK) != 0)
			command[0] = _command_path(env, command[0]);
		if (command[0] == NULL)
		{
			write(1, comm, _strlen(comm));
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
