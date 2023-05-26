#include "lists.h"
#include <stdio.h>

/**
 * print_listtoken - prints all the elements of a listtoken_t list
 * @head: points to the first node
 *
 * Return: the number of nodes
 */
size_t print_listtoken(const listtoken_t *head)
{
	int count = 0;
	const listtoken_t *current;

	if (head == NULL)
		return (0);
	current = head;
	while (current != NULL)
	{
		write(STDOUT_FILENO, current->token, strlen(current->token));
		write(STDOUT_FILENO, "\n", strlen("\n"));
		count++;
		current = current->next;
	}
	return (count);
}
