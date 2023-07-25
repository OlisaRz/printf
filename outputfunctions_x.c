#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * outputfor_x - prints unsigned hexadecimal
 * @n: integer to be checked
 * Rteurn: number length
 */
int outputfor_x(unsigned int n, unsigned int c)
{
	size_t j, len, var, count, rem;
	char *std_o;

	var = n;
	count = 0;
	while (var)
	{
		var /= 16;
		count++;
	}
	len = count;
	std_o = malloc(sizeof(char) * len);
	if (std_o == NULL)
		return (0);
	j = count - 1;
	do
	{
		rem = n % 16;
		if (rem > 9)
		{
			if (c == 1)
				std_o[j] = (rem + 55);
			else
				std_o[j] = (rem + 87);
		}
			else
				std_o[j] = (rem + 48);
			n /= 16;
			j--;
		}
		while (n != 0);
		j = 0;
		while (j < len)
		{
			outputfor_c(std_o[j]);
			j++;
		}
		free(std_o);
		return (len);
	}
