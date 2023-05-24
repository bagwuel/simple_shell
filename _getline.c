#include "main.h"

/**
 * _getline - gets a line of input from a file
 * @lineptr: buffer to store input
 * @n: size of buffer
 * @fd: file descriptor
 *
 * Return: -1 on failure, number of characters read on success
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t num_of_bytes, num_of_char = 0, i, buffer_size;
	char buffer[BUFFER_SIZE];
	static char *tempptr;

	if (lineptr == NULL || n == NULL || fd < 0)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(sizeof(char) * (*n));
		if (*lineptr == NULL)
			return (-1);
	}
	buffer_size = *n;
	tempptr = *lineptr;
	while (1)
	{
		num_of_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_of_bytes == -1)
			return (-1);
		if (num_of_bytes == 0)
			break;
		i = 0;
		while (i < num_of_bytes)
		{
			if (num_of_char >= buffer_size - 1)
			{
				buffer_size = num_of_char * 2;
				*lineptr = _realloc(*lineptr, buffer_size);
				if (*lineptr == NULL)
					return (-1);
				tempptr = *lineptr;
			}
			tempptr[num_of_char++] = buffer[i];
			if (buffer[i] == '\n')
				return (num_of_char);
			i++;
		}
	}
	if (num_of_char == 0)
		return (-1);
	printf("%s\n", *lineptr);
	return (num_of_char);
}
