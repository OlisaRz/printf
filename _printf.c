#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _print_integer - Prints integer
 * @num: Integer to print
 * Return: Number of characters that will be printed
 */
int _print_integer(int num)
{
	char buffer[20]; /* Assuming 20 characters is enough for most integers */
	int len;
	
	len = sprintf(buffer, "%d", num);
	write(1, buffer, len);

	return len;
}

/**
 * _printf - printf function to handle conversion specifiers
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char ch;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = (char)va_arg(args, int);
					write(1, &ch, 1);
					printed_chars++;
					break;
				case 's':
					printed_chars += _print_string(va_arg(args, char *));
					break;
				case '%':
					write(1, &(*format), 1);
					printed_chars++;
					break;
				case 'd':
				case 'i':
					printed_chars += _print_integer(va_arg(args, int));
					break;
				default:
					write(1, "%", 1);
					write(1, &(*format), 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(1, &(*format), 1);
			printed_chars++;
		}
		format++;
	}

	va_end(args);
	
	return printed_chars;
}

/**
 * _print_string - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int _print_string(char *str)
{
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}

	return len;
}
