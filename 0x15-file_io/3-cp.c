#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * exit_error - Print an error message and exit with the specified code.
 * @code: The exit code.
 * @message: The error message.
 */
void exit_error(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * close_file - Close a file descriptor and check for errors.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
		exit_error(100, "Error: Can't close file descriptor");
}

/**
 * copy_file - Copy the content of one file to another file.
 * @from_path: The source file path.
 * @to_path: The destination file path.
 */
void copy_file(const char *from_path, const char *to_path)
{
	int from_fd, to_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	from_fd = open(from_path, O_RDONLY);
	if (from_fd == -1)
		exit_error(98, "Error: Can't read from file");

	to_fd = open(to_path, O_WRONLY | O_CREAT
	| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (to_fd == -1)
		exit_error(99, "Error: Can't write to file");

	while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE) > 0))
	{
		bytes_written = write(to_fd, buffer, bytes_read);

		if (bytes_written == -1)
			exit_error(99, "Error: Can't write to file");
	}

	if (bytes_read == -1)
		exit_error(98, "Error: Can't read from file");

	close_file(from_fd);
	close_file(to_fd);
}

/**
 * main - Main function to copy files.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or an error code (97-100) on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		exit_error(97, "Usage: cp file_from file_to");

	copy_file(argv[1], argv[2]);

	return (0);
}

