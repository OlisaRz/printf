#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++; // Move to the next character after '%'
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += _print_str(va_arg(args, char *));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd': // Integer case
				case 'i':
					printed_chars += _print_integer(va_arg(args, int));
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}
	
	va_end(args);

	return (printed_chars);
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(const char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_str - Writes a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int _print_str(char *str)
{
	int i = 0;
	
	if (str == NULL)
		str = "(null)";
	
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * _print_integer - Prints an integer to stdout.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_integer(int n)
{
	unsigned int num;
	int printed_chars = 0;
	
	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10 != 0)
	{
		printed_chars += _print_integer(num / 10);
	}

	_putchar(num % 10 + '0');
	printed_chars++;

	return (printed_chars);
}

