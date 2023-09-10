#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to a new string containing the concatenated arguments
 *         separated by newline characters ('\n'), or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	char *concatenated_args;
	int total_length = 0, i, j, k = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			total_length++;
		total_length++;
	}

	concatenated_args = malloc((total_length + 1) * sizeof(char));

	if (concatenated_args == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			concatenated_args[k] = av[i][j];
			k++;
		}
		concatenated_args[k] = '\n';
		k++;
	}

	concatenated_args[k] = '\0';
	return (concatenated_args);
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */

int main(int argc, char *argv[])
{
	char *concatenated_args;

	if (argc < 2)
	{
		printf("Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
		return (1);
	}

	concatenated_args = argstostr(argc - 1, argv + 1);

	if (concatenated_args == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	printf("%s", concatenated_args);

	free(concatenated_args);
	return (0);
}

