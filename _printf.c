#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * valid_spec - check if a character is part of the valid format specifier
 * @form - character to be checked
 * Return: 0 if valid, 1 if not valid
 */
int valid_spec(const char *format)
{
	const char *spec = "mat";
	int k = 0;

	while (spec[k] != '\0')
	{
		if (*format == spec[k])
			return (0);
		k++;
	}
	return (1);
}
/**
 * _printf - prints to standard output
 * @format: Passes a single character
 * Return: Returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	size_t x, num, count, length;
	char *s;

	var_start(args, format);
	num = count = length = 0;
	while (*format)
	{
		if (num == 0)
		{
			if (*format != '%')
			{
				format_c(*format);
				count++;
			}
			else
			{
				num = 1;
			}
			else
			{
				if (valid_spec(format))
					length = _putchar(format);
				switch (*format)
				{
					case 'c':
						{
							x = va_arg(args, int);
							length = format_c(x);
							break;
						}
					case 's':
						{
							s = va_arg(args, char *);
							length = format_s(s);
							break;
						}
					default:
						{
							break;
						}
				}
				count += length;
				num = 0;
			}
			format++;
		}
		va_end(args);
		return (count);
	}


