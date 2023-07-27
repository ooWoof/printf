#include "main.c"

/**
 * print_char - prints char
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - prints a string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of char printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
}

/**
 * print_binary - 

