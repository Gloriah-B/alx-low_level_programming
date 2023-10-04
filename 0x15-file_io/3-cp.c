#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024

int open_source_file(const char *file_from);
int open_target_file(const char *file_to);
void close_files(int fd_from, int fd_to);

/**
 * main - Copy the content of one file to another.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success, error codes on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	const char *file_from = argv[1];
	const char *file_to = argv[2];

	int fd_from = open_source_file(file_from);

	if (fd_from == -1)
		return (98);

	int fd_to = open_target_file(file_to);

	if (fd_to == -1)
	{
		close_files(fd_from, -1);
		return (99);
	}

	char buffer[BUFSIZE];
	ssize_t read_result, write_result;

	while ((read_result = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		write_result = write(fd_to, buffer, read_result);
		if (write_result == -1 || write_result != read_result)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close_files(fd_from, fd_to);
			return (99);
		}
	}

	if (read_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close_files(fd_from, fd_to);
		return (98);
	}

	close_files(fd_from, fd_to);

	return (0);
}

/**
 * open_source_file - Open the source file for reading.
 * @file_from: Name of the source file.
 *
 * Return: File descriptor on success, -1 on failure.
 */
int open_source_file(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
	}
	return (fd_from);
}

/**
 * open_target_file - Open the target file for writing.
 * @file_to: Name of the target file.
 *
 * Return: File descriptor on success, -1 on failure.
 */
int open_target_file(const char *file_to)
{
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	}
	return (fd_to);
}

/**
 * close_files - Close file descriptors.
 * @fd_from: File descriptor for the source file.
 * @fd_to: File descriptor for the target file.
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1 && fd_from != -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
	}
	if (close(fd_to) == -1 && fd_to != -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
	}
}

