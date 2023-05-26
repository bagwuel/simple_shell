#include "main.h"

/**
 * char_malloc - allocates memory for a string
 * @str: pointer to character array
 * @size: size of str
 * @err: error to be printed if malloc failed
 *
 * Return: return NULL on failure, pointer to str on success
 */

char *char_malloc(char **str, size_t size, char *err)
{
	*str = (char *) malloc(sizeof(char) * size);
	if (str == NULL)
	{
		perror(err);
		return (NULL);
	}
	return (*str);
}

/**
 * arr_malloc - allocates memory for an array of strings
 * @arr: pointer to array of strings
 * @size: size of arr
 * @err: error to be printed if malloc failed
 *
 * Return: return NULL on failure, pointer to array on success
 */

char **arr_malloc(char **arr, size_t size, char *err)
{
	arr = (char **) malloc(sizeof(char *) * size);
	if (arr == NULL)
	{
		perror(err);
		return (NULL);
	}
	return (arr);
}

/**
 * arraycpy - copies an array of strings
 * @dest: destination array
 * @src: source array
 *
 * Return: return description
 */

int arraycpy(char **dest, char **src)
{
	size_t i, j;

	i = 0;
	while (src[i])
	{
		dest[i] = malloc(sizeof(char) *	strlen(src[i]));
		if (dest[i] == NULL)
		{
			perror("_setenv Error: new_environ[i] malloc failed");
			j = 0;
			while (j < i)
			{
				free(dest[j]);
				j++;
			}
			free(dest);
			return (-1);
		}
		strcpy(dest[i], src[i]);
		i++;
	}
	return (0);
}

/**
 * find_env - checks if an environment variable exits
 * @name: name of environment variable
 *
 * Return: returns index of name if found, -1 otherwise
 */

int find_env(const char *name)
{
	int i, index;

	index = -1;
	i = 0;
	while (__environ[i])
	{
		if (strncmp(__environ[i], name, strlen(name)) == 0)
			index = i;
		i++;
	}
	return (index);
}

/**
 * _envlen - return lenght of environment variable
 * Return: return length of environment variable
 */

int _envlen(void)
{
	unsigned int len;

	len = 0;
	while (__environ[len])
		len++;
	return (len);
}
