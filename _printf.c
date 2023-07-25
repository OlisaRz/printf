#include <unistd.h>
#include "main.h"
/**
 * _printf - The printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				len++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				int i = 0;

				while (str && str[i])
				{
					write(1, &str[i], 1);
					i++;
					len++;
				}
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				len++;
			}
			else
			{
				write(1, "%", 1);
				len++;
				if (*format)
				{
					write(1, format, 1);
					len++;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (len);
}
