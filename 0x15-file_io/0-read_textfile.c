#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - Read and print a text file to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytesRead, bytesWritten;
	FILE *file;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = (char *)malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	bytesRead = fread(buffer, 1, letters, file);
	if (bytesRead < 0)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	buffer[bytesRead] = '\0';

	bytesWritten = write(STDOUT_FILENO, buffer, (size_t)bytesRead);
	if (bytesWritten < 0 || bytesWritten != bytesRead)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);

	return (bytesRead);
}

