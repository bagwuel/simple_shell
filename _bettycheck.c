#include "main.h"

/**
 * _bettycheck - a program that passes betty check
 */

void _bettycheck(void)
{
	char name[] = "Our names are Emmanuel and Tunji\n";
	int i = 0;

	while (name[i])
		_putchar(name[i++]);
}
