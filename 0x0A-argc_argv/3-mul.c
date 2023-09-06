#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 *
 * This program multiplies two integers passed as command-line arguments and
 * prints the result followed by a new line. If it doesn't receive exactly two
 * arguments, it prints "Error", followed by a new line, and returns 1.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 (Success) or 1 (Error)
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	int result = num1 * num2;

	printf("%d\n", result);

	return (0);
}

