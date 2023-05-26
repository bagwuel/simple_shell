#include "main.h"

/**
 * free_tok - free array of strings
 * @tokens: pointer to array of strings
 * @input: string
 */

void free_tok(char **tokens, char *input)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(input);
}

/**
 * free_path - free the path variable
 * @path_var: pointer to path variables
 * @tokens: pointer to tokens
 */
void free_path(char **path_var, char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		i = 0;
		while (tokens[i])
		{
			if (tokens[i] != NULL)
				free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	if (*path_var != NULL)
		free(*path_var);
}
