#include "main.h"
#include <stdio.h>

/**
 * check_and_exit - Check if files can be opened and exit on failure.
 * @src_fd: Source file descriptor.
 * @dest_fd: Destination file descriptor.
 * @src_filename: Source filename.
 * @dest_filename: Destination filename.
 */
void check_and_exit(int src_fd, int dest_fd, const char *src_filename,
		const char *dest_filename)
{
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_filename);
		exit(98);
	}
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_filename);
		exit(99);
	}
}

/**
 * main - Entry point for the file copy program.
 * @argc: Number of arguments.
 * @argv: Argument vector.
 * Return: 0 on success, error codes on failure.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, close_status;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_and_exit(src_fd, dest_fd, argv[1], argv[2]);

	bytes_read = 1024;
	while (bytes_read == 1024)
	{
		bytes_read = read(src_fd, buffer, 1024);
		if (bytes_read == -1)
			check_and_exit(-1, 0, argv[1], argv[2]);
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
			check_and_exit(0, -1, argv[1], argv[2]);
	}

	close_status = close(src_fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	close_status = close(dest_fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}

	return (0);
}

