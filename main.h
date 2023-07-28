#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/*struct for storing format specifiers */
typedef struct specifier_func {
	char specifier;
	int (*function)(char *, va_list);
} specifier_func_t;

/* _printf function */

int _printf(const char *format, ...)
int _print_integer(int num);

/*prototype for the _print_string function*/
int _print_string(char *str);

/*Prototypes for custom conversion specifiers */
int _print_binary(unsigned int num);
int _print_unsigned(unsigned int num);
int _print_octal(unsigned int num);
int _print_hex(unsigned int num);
int _print_hex_upper(unsigned int num);

#endif /* MAIN_H */
