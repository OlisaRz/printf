Printf project by:

Faith Mutunga
Rosemary Olisa

Task 0
Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You dont have to reproduce the buffer handling of the C library printf function
You dont have to handle the flag characters
You dont have to handle field width
You dont have to handle precision
You dont have to handle the length modifiers

Task 1
1. Education is when you read the fine print. Experience is what you get if you don't
mandatory
Handle the following conversion specifiers:

d
i
You dont have to handle the flag characters
You dont have to handle field width
You dont have to handle precision
You dont have to handle the length modifiers

Task 2
Handle the following custom conversion specifiers:

b: the unsigned int argument is converted to binary
alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
1100010
alex@ubuntu:~/c/printf$

Task 3
Handle the following conversion specifiers:

u
o
x
X
You dont have to handle the flag characters
You dont have to handle field width
You dont have to handle precision
You dont have to handle the length modifiers

Task 4
4. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call write as little as possible.

Task 5
Handle the following custom conversion specifier:

S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
alex@ubuntu:~/c/printf$ cat main.c
include main.h

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
Best\x0ASchool
alex@ubuntu:~/c/printf$

Task 6
Handle the following conversion specifier: p.

You dont have to handle the flag characters
You dont have to handle field width
You dont have to handle precision
You dont have to handle the length modifiers
