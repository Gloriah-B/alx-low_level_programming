#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

Node *createNode(int key, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		return (NULL);
	}
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	return (newNode);
}
/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *newTable = (hash_table_t *)malloc(sizeof(hash_table_t));

	if (newTable == NULL)
	{
		printf("Memory allocation failed!\n");
		return (NULL);
	}

	newTable->size = size;
	newTable->array = (Node **)malloc(size * sizeof(Node *));
	if (newTable->array == NULL)
	{
		printf("Memory allocation failed!\n");
		free(newTable);
		return (NULL);
	}

	for (unsigned long int i = 0; i < size; ++i)
	{
		newTable->array[i] = NULL;
	}

	return (newTable);
}
