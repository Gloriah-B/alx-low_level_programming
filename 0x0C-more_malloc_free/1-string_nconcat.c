#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings up to n bytes.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes from s2 to concatenate.
 *
 * Return: A pointer to the concatenated string or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int s1_len, s2_len, result_len, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	if (n >= s2_len)
		result_len = s1_len + s2_len;
	else
		result_len = s1_len + n;

	result = (char *)malloc((result_len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		result[i] = s1[i];

	for (unsigned int j = 0; j < n && j < s2_len; j++, i++)
		result[i] = s2[j];

	result[i] = '\0';

	return (result);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "World!";
	unsigned int n = 5;
	char *result = string_nconcat(s1, s2, n);

	if (result != NULL)
	{
		printf("Concatenated String: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed!\n");
	}

	return (0);
}

