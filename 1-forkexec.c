#include "main.h"

/**
 * _forkexec - creates a child process that executes a command
 * @command: address of the command array
 * @av: programs argument array
 *
 * Return: 1 on failure, 0 on success
 */

int _forkexec(char **command, char *av)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		free(command);
		perror("Fork failed\n");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			write(1, av, strlen(av));
			write(1, ": No such file or directory\n", 28);
		}
	}
	else
	{
		wait(&status);
		free(command);
	}
	return (0);
}
