#ifndef MAIN_H
#define  MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(X) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */

#define F_minus 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: format
 * @fn: function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: format
 * @fm_t: function associated
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i),
var_list list, char buffer[], int precision, int size;

/* functin to print char and strings */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_stringint(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/* functions to print numbers */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, int width, int precision, int size);

/* function to print non printable characters */

int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* function to print memory address */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* function to handle other specifiers */

int get_flagss(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i);
int get_size(const char *format, int *i);

/* function to print string in reverse */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
 /* function to print string in rot 13 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* width handler */

int handler_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int in, char buff[], int flags, int width,
		int precision, int legth, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int legth,
		int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

/* utils */

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif


