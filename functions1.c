#include "main.h"

/**
 * print_unsigned - prints an unsigned number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precisioon specificstion
 * @size: size specifier
 * Return: number of char printed
 */

int print_unsigned(va_list types, char buffer,
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadeximal - prints unsigned number in  hexadecimal
 * @types: list of argument
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precisioon specificstion
 * @size: size specifier
 * Return: number of char printed
 */

int print_hexadecimal(va_list types, char buffer,
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - prints an unsignrd number in upper hexadecimaL
 * @types: list of argument
 * @buffer: buffer array to handle print
 * @flags: calculate active flagS
 * @precision: precisioon specificstion
 *
