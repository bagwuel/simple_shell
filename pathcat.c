#include "main.h"

/**
 * _pathcat - joins a PATH and a command to be executed
 * @str: PATH string
 * @s: command string
 *
 * Return: NULL on failure, pointer to new string on success
 */

char *_pathcat(char *str, char *s)
{
	int i = 0, j = 0;
	char *new_str;

	while (str[i])
		i++;
	while (s[j])
		j++;
	new_str = malloc(sizeof(char) * (i + j) + 2);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = '/';
	j = 0;
	while (s[j])
		new_str[i++] = s[j++];
	new_str[i] = '\0';
	return (new_str);
}
