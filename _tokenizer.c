#include "main.h"

/**
 * _tokenizer - breaks string into array of words
 * @str: string to be tokenized
 *
 * Return: pointer to array
 */

char **_tokenizer(char *str)
{
	char **command;
	int i = 0, j = 1;
	char *token;

	while (str[i])
		if (str[i++] == ' ' || str[i] == '\t')
			j++;
	command = malloc(sizeof(char *) * j + 1);
	if (command == NULL)
	{
		perror("Failed to allocate memory\n");
		return (NULL);
	}
	token = _strtok(str, " \t");
	i = 0;
	while (token != NULL)
	{
		command[i] = token;
		token = _strtok(NULL, " \t");
		i++;
	}
	command[i] = NULL;
	return (command);
}
