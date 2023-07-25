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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int temp = num;
				int digits = 0;
				char negative = 0;

				if (num == 0)
				{
					digits = 1;
				}
				else
				{
					if (num < 0)
					{
						negative = 1;
						num = -num;
						len++;
					}
					while (temp != 0)
					{
						digits++;
						temp /= 10;
					}
				}
				while (digits > 0)
				{
					char digit = (num % 10) + '0';
					write(1, &digit, 1);
					len++;
					num /= 10;
					digits--;
				}
				if (negative)
				{
					write(1, "-", 1);
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
