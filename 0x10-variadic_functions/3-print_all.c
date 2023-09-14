#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on a format string.
 * @format: A list of types of arguments passed to the function
 *   c: char
 *   i: integer
 *   f: float
 *   s: char * (if the string is NULL, print (nil) instead)
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *sep = "";
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (i > 0)
			sep = ", ";

		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				break;
			case 's':
				{
					char *str = va_arg(args, char *);

					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
				}
				break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

