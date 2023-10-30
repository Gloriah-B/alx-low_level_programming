#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/**
 * create_file - Create a file and write text content to it.
 * @filename: The name of the file to create.
 * @text_content: The NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result;
	mode_t permissions = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (file_descriptor == -1)
		return (-1);

	write_result = write(file_descriptor, text_content, strlen(text_content));
	if (write_result == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}

