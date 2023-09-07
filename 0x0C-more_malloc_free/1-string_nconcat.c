#include <stdlib.h>

/**
 * string_nconcat_custom - Concatenates two strings up to n bytes.
 * @str1: The first string.
 * @str2: The second string.
 * @n: The maximum number of bytes from str2 to concatenate.
 *
 * Return: A pointer to the concatenated string or NULL on failure.
 */
char *string_nconcat_custom(char *str1, char *str2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, result_len, i;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";

	for (len1 = 0; str1[len1] != '\0'; len1++)
		;

	for (len2 = 0; str2[len2] != '\0'; len2++)
		;

	if (n > len2)
		n = len2;

	result_len = len1 + n;

	result = malloc(result_len + 1);

	if (result == NULL)
		return (NULL);

	for (i = 0; i < result_len; i++)
	{
		if (i < len1)
			result[i] = str1[i];
		else
			result[i] = str2[i - len1];
	}

	result[i] = '\0';

	return (result);
}

