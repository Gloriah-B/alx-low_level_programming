#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"
/**
 * init_dog - Initializes a struct dog.
 * @d: Pointer to the struct dog to initialize.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = strdup(name);
	d->age = age;
	d->owner = strdup(owner);

	struct dog myDog;

	init_dog(&myDog, "Buddy", 3.5, "John Smith");

	printf("Name: %s\n", myDog.name);
	printf("Age: %.2f\n", myDog.age);
	printf("Owner: %s\n", myDog.owner);

	free(myDog.name);
	free(myDog.owner);

	return (0);
}

