#include "main.h"
#include <stdarg.h>

/**
 * handle_print - Selects the correct function to print depending on the format.
 * @format: A string containing the format to print.
 * @types: A list of arguments.
 * Return: The number of characters printed.
 */
int handle_print(const char *format, va_list types)
{
    int i, j, printed_chars = 0;
    int unknow_len = 0;

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            j = 0;
            while (fmt_types[j].fmt != NULL)
            {
                if (format[i + 1] == fmt_types[j].fmt[0])
                {
                    printed_chars += fmt_types[j].f(types);
                    break;
                }
                j++;
            }
            if (fmt_types[j].fmt == NULL)
            {
                write(1, &format[i], 1);
                printed_chars++;
                unknow_len++;
            }
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            printed_chars++;
        }
    }

    if (unknow_len != 0)
        return (-1); // Return -1 if there's an unknown format specifier.
    else
        return (printed_chars);
}

