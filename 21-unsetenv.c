#include "main.h"

/**
 * unsetenv - unsets an environment variable
 * @name: name of environment variable
 *
 * Return: return -1 on failur 0 on success
 */

int unsetenv(const char *name)
{
	unsigned int index;
	int i, j, env_at;
	char **new_env;

	new_env = NULL;
	index = _envlen();
	env_at = find_env(name);
	if (env_at != -1)
	{
		new_env = arr_malloc(new_env, index, "_unsetenv Error: new_env malloc fail");
		i = 0;
		while (__environ[i])
		{
			if (i != env_at)
			{
				new_env[i] = malloc(sizeof(char) * strlen(__environ[i]));
				if (new_env[i] == NULL)
				{
					j = 0;
					perror("_unsetenv Error: new_env[i] malloc failed");
					while (j < i)
					{
						free(new_env[j]);
						j++;
					}
					free(new_env);
					return (-1);
				}
				strcpy(new_env[i], __environ[i]);
			}
			i++;
		}
		new_env[index] = NULL;
		__environ = new_env;
	}
	return (0);
}
