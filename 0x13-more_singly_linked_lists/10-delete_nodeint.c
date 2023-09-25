#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at given index in list
 * @head: A pointer to a pointer to the head of the listint_t list.
 * @index: The index of the node to delete, starting at 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	while (count < index - 1)
	{
		current = current->next;
		if (current == NULL)
			return (-1);
		count++;
	}

	temp = current->next;
	if (temp == NULL)
		return (-1);

	current->next = temp->next;
	free(temp);
	return (1);
}

