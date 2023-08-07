#include "main.h"

/**
 * create_file - function creates a file
 * @filename: name of the file to create
 * @text_content: null terminated string to write to the file
 *
 * Return: 1 success or failure -1
 */
int create_file(const char *filename, char *text_content)
{
	int qrn, qrs, qrt = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (qrt = 0; text_content[qrt];)
			qrt++;
	}

	qrn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	qrs = write(qrn, text_content, qrt);

	if (qrn == -1 || qrs == -1)
		return (-1);

	close(qrn);

	return (1);
}
