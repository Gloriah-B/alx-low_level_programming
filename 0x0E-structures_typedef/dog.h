#ifndef DOG_H
#define DOG_H

/**
 * struct dog - refer to dog basic info
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner of the dog
 * Description: This struct stores information about a dog,
 * including its name, age, and owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
}

#endif
