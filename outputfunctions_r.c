#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _memcpy - copy memory area
 * @dest: Destination after copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * rev_string - reverses string
 * @s: string to reverse
 * Return: a Pointer to a character
 */
int rev_string(char *s)
{
	int i, len = 0;
	char *ptr;
	char tmp;

	while (s[len] != '\0')
		len++;
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (-1);
	_memcpy(ptr, s, len);
	for (i = 0; i < len; i++, len--)
	{
		tmp = ptr[len - 1];
		ptr[len - 1] = ptr[i];
		ptr[i] = tmp;
	}
	i = 0;
	while (ptr[i] != '\0')
	{
		outputfor_c(ptr[i]);
		i++;
	}
	free(ptr);
	return (len);
}
