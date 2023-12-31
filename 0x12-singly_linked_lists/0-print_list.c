#include <stdio.h>
#include "lists.h"

/**
 * print_list - Print all elements of a list_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%lu] (nil)\n", 0lu);
		else
			printf("[%lu] %s\n", (unsigned long)h->len, h->str);

		h = h->next;
		count++;
	}

	return (count);
}
