#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - function returns a pointer duplicate to new memory
 * @str: pointer to a charcter
 * Return: 0
 */

char *_strdup(char *str)
{
	char *xyz;
	int j, r = 0;

	if (str == NULL)

		return (NULL);

	j = 0;
	while (str[j] != '\0')
		j++;
	xyz = malloc(sizeof(char) * (j + 1));

	if (xyz == NULL)
		return (NULL);
	for (r = 0; str[r]; r++)
		xyz[r] = str[r];

	return (xyz);
}
