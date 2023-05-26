#include "main.h"

/**
 * _handle_signal - handle signals
 * @sig: signal
 */

void _handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
