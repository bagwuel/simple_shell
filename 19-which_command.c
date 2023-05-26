#include "main.h"

/**
 * is_path - checks if file path is a valid path
 * @path: file path to be checked
 *
 * Return: 1 if executable 0 otherwise
 */

int is_path(char *path)
{
	size_t len = strlen(path);

	if (len >= strlen("../"))
		if (strncmp(path, "../", strlen("../")) == 0)
			return (1);
	if (len >= strlen("./"))
		if (strncmp(path, "./", strlen("./")) == 0)
			return (1);
	if (len >= strlen("/"))
		if (strncmp(path, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * path_gen - generates a file path
 * @file_path: the full path to be generated
 * @tokens: path to be concatenated
 * @filename: filename to be concatenated to path
 * @index: token index to be copied
 */

void path_gen(char **file_path, char **tokens, char *filename, int index)
{
	char_malloc(file_path,
			(strlen(tokens[index]) + strlen(filename) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, tokens[index]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _which - returns path to file
 * @filename: argument_1 description
 *
 * Return: return NULL on failure,path to file on success
 */

char *_which(char *filename)
{
	struct stat sb;
	char *path_var, *delimiter, *file_path;
	char **tokens;
	int index, path_exist;

	delimiter = ":";
	path_var = _getenv("PATH");
	if (path_var != NULL)
	{
		tokens = tokenizer(path_var, delimiter);
		if (tokens != NULL)
		{
			index = 0;
			while (tokens[index])
			{
				path_gen(&file_path, tokens, filename, index);
				path_exist = stat(file_path, &sb);
				if (path_exist == 0)
				{
					free_path(&path_var, tokens);
					return (file_path);
				}
				free(file_path);
				index++;
			}
			free_path(&path_var, tokens);
		}
		else
			free(path_var);
	}
	path_exist = stat(filename, &sb);
	if (path_exist == 0 && is_path(filename))
		return (strdup(filename));
	return (NULL);
}
