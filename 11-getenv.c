#include "main.h"

/**
 * _getenv - short description
 * @name: name of environment variable
 *
 * Return: return NULL on failure, pointer to env variable on success
 */

char *_getenv(const char *name)
{
	char *env_var;
	char *envcpy;
	unsigned int i = 0, len;

	while (__environ[i])
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
		{
			len = strlen(__environ[i]) - (strlen(name));
			env_var = malloc(sizeof(char) * len);
			if (env_var == NULL)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			char_malloc(&envcpy, strlen(__environ[i]) + 1, "_getenv malloc error");
			strcpy(envcpy, __environ[i]);
			strncpy(env_var, envcpy += (strlen(name) + 1), len);
			free(envcpy -= (strlen(name) + 1));
			return (env_var);
		}
		i++;
	}
	return (NULL);
}
