#include <unistd.h>
#include <string.h>
#include <stddef.h>
/**
 * outputfor_s - Prints string to standard output
 * @str: string to be checked
 * Return: length of string
 */
int outputfor_s(char *str)
{
	size_t len = strlen(str);

	if (len > 0)
	{
		write(1, str, len);
	}
	return len;
}
