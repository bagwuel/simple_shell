#include "main.h"

/**
 * make_env - creates an envirionment variable
 * @envar: environment variable to be made
 * @len: length of envar
 * @name: name of environment variable
 * @val: value of environment variable
 */

void make_env(char **envar, unsigned int len, const char *name,
		const char *val)
{
	*envar = char_malloc(envar, len, "_setenv Error: envar malloc failed");
	len = strlen(name) + strlen(val) + 2;
	*envar = char_malloc(envar, len, "_setenv Error: envar malloc failed");
	strcpy(*envar, name);
	strcat(*envar, "=");
	strcat(*envar, val);
	strcat(*envar, "\0");
}

/**
 * is_env - checks if an environment variable exist already
 * @envar: evnvironment variable
 * @len: length of envar
 * @name: name of environment variable
 * @overwriter: indicates if an environment variable should be overwritten
 *
 * Return: -1 if error, 0 on success
 */
int is_env(char *envar, unsigned int len, const char *name, int overwriter)
{
	unsigned int i = 0;

	while (__environ[i])
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0 && overwriter != 0)
		{
			free(__environ[i]);
			__environ[i] = malloc(sizeof(char) * len);
			if (__environ[i] == NULL)
			{
				perror("_setenv Error: __environ[i] malloc failed");
				free(envar);
				return (-1);
			}
			strcpy(__environ[i], envar);
			free(envar);
			return (0);
		}
		i++;
	}
	return (0);
}

/**
 * not_env - check if an environment variable is not present
 * @envar: environment variable to be checked
 * @len: length of envar
 * @envlen: length of enviroment
 *
 * Return: return -1 on error, 0 on success
 */

int not_env(char *envar, unsigned int len, unsigned int envlen)
{
	unsigned int i;
	char **new_env;

	new_env = (char **) malloc(sizeof(char *) * (envlen + 2));
	if (new_env == NULL)
	{
		perror("_setenv Error: new_env malloc failed");
		free(envar);
		return (-1);
	}
	arraycpy(new_env, __environ);
	new_env[envlen] = malloc(sizeof(char) * len);
	if (new_env[envlen] == NULL)
	{
		i = 0;
		perror("_setenv Error: new_env[i] malloc failed");
		while (i < envlen)
		{
			free(new_env[i]);
			i++;
		}
		free(new_env);
		free(envar);
		return (-1);
	}
	strcpy(new_env[envlen], envar);
	new_env[envlen + 1] = NULL;
	free(envar);
	__environ = new_env;
	return (0);
}

/**
 * setenv - set environment variable
 * @name: name of environment variable
 * @val: value of environment variable
 * @overwriter: indicated if an environment variable is to be over written
 *
 * Return: (0)
 */
int setenv(const char *name, const char *val, int overwriter)
{
	unsigned int len;
	char *envar;

	len = strlen(name) + strlen(val) + 2;
	make_env(&envar, len, name, val);
	is_env(envar, len, name, overwriter);
	if (find_env(name) != -1)
		is_env(envar, len, name, overwriter);
	else
		not_env(envar, len, _envlen());
	return (0);
}
