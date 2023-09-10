#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * Description - function implements is_whitespace function
 * @is_whitespace - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if the character is a whitespace character, 0 otherwise.
 */
int is_whitespace(char c)

/**
 * Description - functio n implements count_words
 *@count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)

/**
 * strtow - Splits a string into words.
 * @str: The input string to split.
 *
 * Return: A pointer to an array of strings (words).
 * Each element of the array contains a single word, null-terminated.
 * The last element of the returned array is NULL.
 * Returns NULL if str == NULL or str == "".
 * If the function fails, it returns NULL.
 */
char **strtow(char *str)
{
	int num_words;
	char **words;
	int word_index = 0;
	int word_length = 0;
	int i;
	int j;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);

	}

	num_words = count_words(str);

	if (num_words == 0)
	{
	return (NULL);
	}

	words = (char **)malloc((num_words + 1) * sizeof(char *));

	if (words == NULL)
	{
	return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
	if (!is_whitespace(str[i]))
	{
		if (word_length == 0)
		{
			word_length++;
			words[word_index] = (char *)malloc(word_length * sizeof(char));
		}
		else
		{
			word_length++;
			words[word_index] = (char *)realloc(words[word_index],
					word_length * sizeof(char));
		}

	if (words[word_index] == NULL)
	{
		for (j = 0; j < word_index; j++)
		{
			free(words[j]);
		}

		free(words);
		return (NULL);
	}

	words[word_index][word_length - 1] = str[i];
	}
	else
	{
		if (word_length > 0)
	{
		words[word_index][word_length] = '\0';
		word_length = 0;
		word_index++;
	}
	}
	}

	if (word_length > 0)
	{
		words[word_index][word_length] = '\0';
		word_index++;
	}


	words[word_index] = NULL;

	return (words);
}
