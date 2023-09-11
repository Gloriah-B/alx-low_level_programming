#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * init_dog - function initializes a variable of type struct dog
 * @d: pointer to struct dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog))
	d->name = strdup(name);
	d->age = age;
	d->owner = strdup(owner);

}


