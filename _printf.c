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
	int length;
	
	length = sprintf(buffer, "%d", num);
	write(1, buffer, length);

	return length;
}

/**
 * _printf - printf function to handle conversion specifiers
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int expected_char = 0;
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
					expected_char++;
					break;
				case 's':
					expected_char += _print_string(va_arg(args, char *));
					break;
				case '%':
					write(1, &(*format), 1);
					expected_char++;
					break;
				case 'd':
				case 'i':
					expected_char += _print_integer(va_arg(args, int));
					break;
				default:
					write(1, "%", 1);
					write(1, &(*format), 1);
					expected_char += 2;
					break;
			}
		}
		else
		{
			write(1, &(*format), 1);
			expected_char++;
		}
		format++;
	}

	va_end(args);
	
	return expected_char;
}

/**
 * _print_string - Print a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int _print_string(char *str)
{
	int length = 0;

	if (str == NULL)
		str = "(null)";

	while (str[length])
	{
		write(1, &str[length], 1);
		length++;
	}

	return length;
}
