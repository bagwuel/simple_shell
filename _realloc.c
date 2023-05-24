#include "main.h"

/**
 * _realloc - reallocates memory
 * @ptr: pointer to memory to be reallocated
 * @size: size of new memory block
 *
 * Return: NULL on failure, pointer to new block on success
 */

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		_memcpy(new_ptr, ptr, size / 2);
		free(ptr);
	}
	return (new_ptr);
}
