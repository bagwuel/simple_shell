#include "main.h"

/**
 * _prompt - prompts the user for an input
 *
 * Return: NULL on failure, pointer to input on success
 */

char *_prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	int i = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	if (*line == '\n')
		return (line);
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}
