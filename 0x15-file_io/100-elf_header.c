#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *elf_header);

int main(int argc, char *argv[]);
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
		return (98);
	}

	Elf64_Ehdr elf_header;
	ssize_t bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));

	if (bytes_read != sizeof(Elf64_Ehdr) ||
		elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file: %s\n", argv[1]);
		return (98);
	}

	printf("ELF Header:\n");
	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}

void print_elf_header_info(Elf64_Ehdr *elf_header);
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("  Class:  %s\n", (elf_header->e_ident[EI_CLASS] == ELFCLASS32) ?
	"ELF32" : "ELF64");
	printf("  Data:   %s\n", (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" :
		"2's complement, big endian");
	printf("  Version:    %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI: %d\n", elf_header->e_ident[EI_OSABI]);
	printf("  ABI Version:    %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:   %s\n",
		   (elf_header->e_type == ET_REL) ? "REL (Relocatable file)" :
		   (elf_header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
		   (elf_header->e_type == ET_DYN) ? "DYN (Shared object file)" :
		   (elf_header->e_type == ET_CORE) ? "CORE (Core file)" : "UNKNOWN");
	printf("  Entry point address:    0x%lx\n",
			(unsigned long)elf_header->e_entry);
}

