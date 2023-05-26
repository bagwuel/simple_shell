#include "main.h"

/**
 * prompt - displays a prompt character on the standard output
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
