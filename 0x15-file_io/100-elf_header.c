#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verifyElfHeader(unsigned char *e_ident);
void printMagicNumbers(unsigned char *e_ident);
void printHeaderClass(unsigned char *e_ident);
void printDataFormat(unsigned char *e_ident);
void printHeaderVersion(unsigned char *e_ident);
void printOSABI(unsigned char *e_ident);
void printABIVersion(unsigned char *e_ident);
void printFileType(unsigned int e_type, unsigned char *e_ident);
void printEntryPoint(unsigned long int e_entry, unsigned char *e_ident);
void closeFile(int fileDescriptor);

/**
 * verifyElfHeader - Verify that the file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void verifyElfHeader(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void printMagicNumbers(unsigned char *e_ident)
{
	int index;

	printf("Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * printHeaderClass - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printHeaderClass(unsigned char *e_ident)
{
	printf("Class:  ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * printDataFormat - Prints the data format of an ELF header.
 * @e_ident: A pointer to an array containing the data format.
 */
void printDataFormat(unsigned char *e_ident)
{
	printf("Data:  ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}
/**
 * printHeaderVersion - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printHeaderVersion(unsigned char *e_ident)
{
	printf("Version:  %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * printOSABI - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printOSABI(unsigned char *e_ident)
{
	printf("OS/ABI:  ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * printABIVersion - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void printABIVersion(unsigned char *e_ident)
{
	printf("ABI Version:  %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * printFileType - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printFileType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("Type:  ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}
/**
 * printEntryPoint - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void printEntryPoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address:  ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * closeFile - Closes the ELF file.
 * @fileDescriptor: The file descriptor of the ELF file.
 */
void closeFile(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fileDescriptor);
		exit(98);
	}
}
/**
 * main - Displays information from the ELF header of a given file.
 * @argc: The number of arguments passed to the program (unused).
 * @argv: An array of pointers to the program's command-line arguments.
 * Return: 0 on successful execution, 98 on error (e.g., file not found or
 * not a valid ELF file).
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, bytesRead;

	fileDescriptor = open(argv[1], O_RDONLY);

	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr);

	if (header == NULL)

	{
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	bytesRead = read(fileDescriptor, header, sizeof(Elf64_Ehdr));

	if (bytesRead == -1)
	{
		free(header);
		closeFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Unable to read file: %s\n", argv[1]);
		exit(98);
	}

	verifyElfHeader(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printHeaderClass(header->e_ident);
	printDataFormat(header->e_ident);
	printHeaderVersion(header->e_ident);
	printOSABI(header->e_ident);
	printABIVersion(header->e_ident);
	printFileType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeFile(fileDescriptor);
	return (0);
}	

