#include "main.h"

int main(int ac, char **av, char **env)
{
	char *prompt = "#cisfun$ ";
	char *line = NULL, *token;
	size_t len = 0;
	char **command;
	int i, j, status;
	pid_t child_pid;

	if (ac != 1)
	{
		perror("Usage: ./shell\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if(isatty(STDIN_FILENO))
			write(1, prompt, strlen(prompt));
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (*line == '\n')
			continue;
		i = 0;
		j = 1;
		while (line[i])
		{
			if (line[i] == ' ')
				j++;
			if (line[i] == '\n')
				line[i] = '\0';
			i++;
		}
		command = malloc(sizeof(char *) * j);
		if (command == NULL)
		{
			perror("Failed to allocate memory\n");
			free(line);
			exit(EXIT_FAILURE);
		}
		token = strtok(line, " ");
		i = 0;
		while (token != NULL)
		{
			command[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		command[i] = NULL;
		/*if (access(command[0], X_OK) != 0)
		{
			continue;
		}*/
		child_pid = fork();
		if (child_pid == -1)
		{
			free(command);
			perror("Fork failed\n");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
			{
				write(1, av[0], strlen(av[0]));
				write(1, ": No such file or directory\n", 28);
			}
		}
		else
		{
			wait(&status);
			free(command);
		}
	}
	return (0);
}
