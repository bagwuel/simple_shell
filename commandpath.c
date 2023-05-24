#include "main.h"

/**
 * _command_path - checks the PATH variable for a particular command
 * @env: programs environment variable
 * @command: command to be checked for
 *
 * Return: full path of command on success, NULL on failure
 */

char *_command_path(char **env, char *command)
{
	int i = 0;
	char *token, *new_env, *full_path;

	while (env[i])
	{
		new_env = strdup(env[i]);
		token = strtok(new_env, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, ":");
			while (token != NULL)
			{
				full_path = _pathcat(token, command);
				if (access(full_path, X_OK) == 0)
					return (full_path);
				token = strtok(NULL, ":");
			}
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
