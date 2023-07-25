#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * valid_spec - check if a character is part of the valid format specifier
 * @form - character to be checked
 * @outputfor_c: conversion specifier
 * @outputfor_s: conversion specifier
 * Return: 0 if valid, 1 if not valid
 */
int valid_spec(const char *format)
{
	const char *spec = "rbdicuxXos";
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
 * _putchar - prints the character value
 * @format: format passed to the function
 * Return: 1
 */
int _putchar(const char *format)
{
	char c = *format;

	write(1, &c, 1);
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

	va_start(args, format);
	num = count = length = 0;

	while (*format)
	{
		if (num == 0)
		{
			if (*format != '%')
			{
				outputfor_c(*format);
				count++;
			} 
			else
			{
				num = 1;
			}
		} 
		else
		{
			if (valid_spec(format))
			{
				length = _putchar(format);
				switch (*format)
				{
					case 'c':
						{
							x = va_arg(args, int);
							length = outputfor_c(x);
							break;
						}
					case 's':
						{
							s = va_arg(args, char *);
							length = outputfor_s(s);
							break;
						}
					case 'd':
						{
							x = va_arg(args, int);
							length = outputfor_d(x);
							break;
						}
					case 'i':
						{
							x = va_arg(args, int);
							length = outputfor_i(x);
							break;
						}
					case 'b':
						{
							x = va_arg(args, int);
							length = outputfor_b(x);
							break;
						}
					case 'o':
						{
							x = va_arg(args, int);
							length = outputfor_o(x);
							break;
						}
					case 'X':
						{
							x = va_arg(args, int);
							break;
						}
					case 'x':
						{
							x = va_arg(args, int);
							break;
						}
					case 'r':
						{
							s = va_arg(args, char *);
							length = rev_string(s);
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
		}
		format++;
	}
	va_end(args);
	return (count);
}
	
	

	
