#include "main.h"

/**
 * main - simple shell program
 * @ac: size of command line arguments
 * @av: command line argument vector
 * @env: environment variable
 *
 * Return: return (0)
 */

int main(int ac, char **av, char **env)
{
	char **tokens;
	char *input = NULL, *delim = " \n", *which;
	size_t malloc_size = 0, cmd_size = 0;
	int status = 0;
	(void) ac;
	(void) av;
	(void) env;

	signal(SIGINT, _handle_signal);
	while (1)
	{
		cmd_size++;
		_getline(&input, &malloc_size, status);
		tokens = tokenizer(input, delim);
		if (!(*tokens))
			status = 0;
		else
		{
			if (is_builtin_cmd(tokens))
			{
				if (handle_builtin(tokens) == EXIT_CODE)
				{
					free_tok(tokens, input);
					exit(status);
				}
			}
			else
			{
				which = _which(tokens[0]);
				if (which !=  NULL)
					status = _fork(which, tokens);
				else
					status = handle_errors(av, tokens, cmd_size);
			}
		}
		free_tok(tokens, input);
		input = NULL;
	}
	return (0);
}
