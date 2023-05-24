#include "main.h"

/**
 * f_exit - exits a shell termoinal with a status
 * @status: status
 */

void f_exit(char *status)
{
	if (!status)
		exit(1);
	else
		exit(_atoi(status));
}
