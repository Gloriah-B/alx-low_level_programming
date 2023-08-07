#include "main.h"

/**
 * read_textfile -function reads txt file and prints std output
 * @filename: refers to filename
 * @letters: no of letters it should read and print
 *
 * Return: no of letters printed(success) Failure or Null returns 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int qrn;
	ssize_t qrs, qrt;
	char *buffer;

	if (!filename)
		return (0);

	qrn = open(filename, O_RDONLY);

	if (qrn == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	qrs = read(qrn, buffer, letters);
	qrt = write(STDOUT_FILENO, buffer, qrs);

	close(qrn);

	free(buffer);

	return (qrt);
}
