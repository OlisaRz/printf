#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/*First task prototype*/
int _printf(const char *format, ...);

/*function that produces output according to a format*/
int outputfor_c(char);
int outputfor_s(char *);

/**
 * _putchar - prints the character value
 * @format: passed to the function
 * Return: 1
 */
int _putchar(const char *format)
{
	char c = *format;
	write(1, &c, 1);
	return (1);
}

int outputfor_d(int);
int outputfor_b(unsigned int);
int outputfor_u(unsigned int);
int outputfor_o(unsigned int);
int outputfor_x(unsigned int n, unsigned int c);
int outputfor_i(unsigned int);

int rev_string(char *);
int format_x(unsigned int, unsigned int);
char *_buffer(char *);
void _reset_buffer(char *);
#endif
