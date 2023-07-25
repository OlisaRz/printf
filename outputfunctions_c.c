#include "main.h"
#include <unistd.h>
/**
 * outputfor_c - prints to standard output
 * ch: character to be checked
 * Return: 1
 */
int outputfor_c(char ch)
{
	write(1, &ch, 1);
	return (1);
}
