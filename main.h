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

int outputfor_d(int);
int outputfor_b(unsigned int);
int outputfor_u(unsigned int);
int outputfor_o(unsigned int);

int rev_string(char *);
int format_x(unsigned int, unsigned int);
char *_buffer(char *);
void _reset_buffer(char *);
#endif
