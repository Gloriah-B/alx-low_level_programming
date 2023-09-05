#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two stringd s1 and s2
 * @s1: pointer one to concat
 * @s2: pointer two to concat
 * Return: concat of s1 and s2(success)
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenate;
	int i, ci;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = ci = 0;
	while (s1[i] != '\0')
	i++;
	while (s2[ci] != '\0')
		ci++;
	concatenate = malloc(sizeof(char) * (i + ci + 1));

	if (concatenate == NULL)
		return (NULL);
	i = ci = 0;
	while (s1[i] != '\0')
	{
		concatenate[i] = s1[i];
		i++;
	}

	while (s2[ci] != '\0')
	{
		concatenate[i] = s2[ci];
		i++, ci++;
	}
	concatenate[i] = '\0';
	return (concatenate);
}

