#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _print_binary - Print unsigned integer in binary
 * @num: The integer to print
 *
 * Return: Number of characters printed
 */
int _print_binary(unsigned int num)
{
	char binary_buffer[65];
	int length = 0;

	if(num == 0)
	{
		binary_buffer[0] = '0';
		length = 1;
	}
	else
	{
		int i;
		for (i = 0; i < 64; i++)
		{
			binary_buffer[i] = (num & 1) ? '1' : '0';
			num >>= 1;
		}
		binary buffer[i] = '\0';
		length = 64;
	}
	write(1, binary_buffer, length);
	return (length);
}
