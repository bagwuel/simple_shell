#include "main.h"

/**
 * _count_token - returns number of tokens in a string
 * @input: string to be tokenized
 * @delim: a string of delimiters
 *
 * Return: -1 on failure, number of tokens in string on success
 */
size_t _count_token(char *input, char *delim)
{
	char *token;
	size_t num_of_tokens = 0;

	token = strtok(input, delim);
	while (token != NULL)
	{
		num_of_tokens++;
		token = strtok(NULL, delim);
	}
	return (num_of_tokens);
}

/**
 * tokenizer - creates a NULL terminated array of a string
 * @input: string to be tokenized
 * @delim: string of delimiters
 *
 * Return: returns NULL on failure, tokenized string on success
 */

char **tokenizer(char *input, char *delim)
{
	char **tokens;
	char *temp_input, *token;
	size_t count, index, free_index;

	tokens = NULL;
	char_malloc(&temp_input, strlen(input) + 1,
			"tokenizer Error: temp_input malloc failed");
	strcpy(temp_input, input);
	count = _count_token(temp_input, delim);
	tokens = arr_malloc(tokens, count + 1,
			"tokenizer Error: tokens malloc failed");
	strcpy(temp_input, input);
	token = strtok(temp_input, delim);
	index = 0;
	while (index < count)
	{
		tokens[index] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (tokens[index] == NULL)
		{
			free_index = 0;
			while (free_index < index)
				free(tokens[free_index++]);
			free(temp_input);
			free(tokens);
			perror("tokenizer Error: tokens malloc failed");
			return (NULL);
		}
		strcpy(tokens[index], token);
		token = strtok(NULL, delim);
		index++;
	}
	free(temp_input);
	tokens[count] = NULL;
	return (tokens);
}
