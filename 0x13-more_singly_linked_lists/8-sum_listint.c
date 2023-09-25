#include <stddef.h>
#include "lists.h"

/**
 * sum_listint - Returns sum of all data (n) of a listint_t list
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The sum of all the data (n) in the list, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

