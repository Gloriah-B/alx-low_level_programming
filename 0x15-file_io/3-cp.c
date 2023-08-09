#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * close_file - function closes file
 * @fd: refers to the file description to be closed
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
int main(int argc, char *argv[])
{
	int frm, towards, rd, wt;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	frm = open(argv[1], O_RDONLY);
	if (frm == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	towards = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (towards == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	close_file(frm);
	exit(99);
	}

	while ((rd = read(frm, buffer, BUFFER_SIZE)) > 0)
	{
		wt = write(towards, buffer, rd);
		if (wt == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file(frm);
			close_file(towards);
			exit(99);
		}
	}if (rd == -1)

	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	close_file(frm);
	close_file(towards);
	exit(98);
	}
	
	close_file(frm);
	close_file(towards);

	return (0);
}

