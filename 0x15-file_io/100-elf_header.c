#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * exit_error - Print an error message to stderr and exit with specified code
 *
 * @code: The exit code.
 * @message: The error message.
 */
void exit_error(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}
/**
 * print_elf_header_info - Print information from the ELF header.
 *
 * @header: A pointer to the ELF header.
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                  %s\n", (header->e_ident[EI_CLASS] ==
		ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                   %s\n", (header->e_ident[EI_DATA] ==
		ELFDATA2LSB) ? "2's complement, little-endian" :
		"2's complement, big-endian");
	printf("  Version:                %d (current)\n", header -
			> e_ident[EI_VERSION]);
	printf("  OS/ABI:                 %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:            %d\n", header->e_ident
			[EI_ABIVERSION]);
	printf("  Type:                   %d\n", header->e_type);
	printf("  Entry point address:    0x%lx\n",
		(unsigned long)header->e_entry);
}

/**
 * main - Entry point for the ELF header information program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		exit_error(98, "Usage: elf_header elf_filename");
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		exit_error(98, "Error: Cannot open file");
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read == -1)
	{
		close(fd);
		exit_error(98, "Error: Cannot read file");
	}

	if (bytes_read != sizeof(header) || memcmp(header.e_ident,
		ELFMAG, SELFMAG) != 0)
	{
		close(fd);
		exit_error(98, "Error: Not an ELF file");
	}

	print_elf_header_info(&header);

	close(fd);
	return (0);
}

