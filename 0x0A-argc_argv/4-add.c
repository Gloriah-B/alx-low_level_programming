#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * validateInput - Check if a string contains only digits.
 * @input: The input string to validate.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
int validateInput(char *input)
{
	int j = 0;

	while (input[j])
	{
		if (!isdigit(input[j]))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 (Success) or 1 (Error)
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i = 1;
	char *input;
	int j;
	int number;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (i < argc)
	{
		input = argv[i];
		j = 0;
		number = 0;

		while (input[j])
		{
			if (!isdigit(input[j]))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}

		number = atoi(input);

		if (number > 0)
		{
			sum += number;
		}
		i++;
	}
	printf("%d\n", sum);

	return (0);
}
