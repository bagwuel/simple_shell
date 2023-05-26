#include "main.h"

/**
 * _fork - creates a child process and executes a command
 * @tokens: pointer to command arguments
 * @command: command to be executed
 *
 * Return: return -1 on failure, 0 or exit status on success
 */

int _fork(char *command, char **tokens)
{
	pid_t pid;
	int status, exec_return_value;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork Error: unable to create child process");
		return (-1);
	}
	if (pid == 0)
	{
		exec_return_value = execve(command, tokens, __environ);
		if (exec_return_value == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
