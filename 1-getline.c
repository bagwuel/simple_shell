#include "main.h"

/**
 * _getline - gets a line of input from a file
 * @input: buffer to store input
 * @n: size of buffer
 * @status: the exit status
 *
 * Return: -1 on failure, number of chars read otherwise
 */

ssize_t _getline(char **input, size_t *n, int status)
{
	ssize_t num_of_chars;

	prompt();
	num_of_chars = getline(input, n, stdin);
	if (num_of_chars == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (num_of_chars);
}
