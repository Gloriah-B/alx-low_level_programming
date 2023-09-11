#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog and returns a pointer to it.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: newly created dog, or NULL if memory allocation fails.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog = malloc(sizeof(dog_t));

	if (newDog == NULL)
		return (NULL);

	newDog->name = strdup(name);
	newDog->owner = strdup(owner);

	if (newDog->name == NULL || newDog->owner == NULL)
	{
		free(newDog->name);
		free(newDog->owner);
		free(newDog);
		return (NULL);
	}

	newDog->age = age;

	return (newDog);
}


/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	dog_t *myDog = new_dog("Buddy", 3.5, "John Smith");

	if (myDog == NULL)
	{
		printf("Failed to create a new dog.\n");
		return (1);
	}

	printf("Name: %s\n", myDog->name);
	printf("Age: %.2f\n", myDog->age);
	printf("Owner: %s\n", myDog->owner);

	free(myDog->name);
	free(myDog->owner);
	free(myDog);

	return (0);
}

