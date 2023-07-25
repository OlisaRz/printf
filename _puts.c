#include "main.h"
/**
 * _puts - prints to standard output
 * @str: the string to print
 * Retrun: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}
/**
 * _putchar - writes the character c to buffer
 * @c: The character to print
 * Return: 1 success
 * On error, -1 is returned and errno is set appropriately
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
