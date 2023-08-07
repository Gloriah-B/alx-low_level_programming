#include "main.h"

/**
 * append_text_to_file - function appends text at the end of a file
 * @filename: refers to the name of the file
 * @text_content: the null terminated string to add to the end of the file
 *
 * Return: 1 for success -1 if file does not exist
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int qrn, qrs, qrt = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (qrt = 0; text_content[qrt];)
			qrt++;
	}

	qrn = open(filename, O_WRONLY | O_APPEND);
	qrs = write(qrn, text_content, qrt);

	if (qrn == -1 || qrs == -1)
		return (-1);

	close(qrn);

	return (1);
}
