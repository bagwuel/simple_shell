#include "main.h"

/**
 * handle_errors - Print error messages
 * @av: argument array
 * @tokens: pointer toarray of strings
 * @num: number of commands
 *
 * Return: int status
 */

int handle_errors(char **av, char **tokens, size_t num)
{
	char *err_msg;
	char *num_str = _itoa(num);
	int size = (strlen(av[0]) + (2 * strlen(": ")) +
			num_of_chars(num) + strlen(tokens[0]) +
			strlen(": not found\n") + 1);

	char_malloc(&err_msg, size, "error_not_found Error: malloc error");
	strcpy(err_msg, av[0]);
	strcat(err_msg, ": ");
	strcat(err_msg, num_str);
	strcat(err_msg, ": ");
	strcat(err_msg, tokens[0]);
	strcat(err_msg, ": not found\n");
	strcat(err_msg, "\0");

	write(STDERR_FILENO, err_msg, strlen(err_msg));
	free(err_msg);
	free(num_str);
	return (127);
}
