#include "lists.h"

/**
 * print_listint - function prints all the elements of a listint_t list
 * @h: pointer to the head of the nodes
 *
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)

{
	size_t nodes = 0;

	while (h)
	{
		h = h->next;
		printf("%d\n", h->n);
		nodes++;
	}
	return (nodes);
}
