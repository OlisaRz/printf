#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * outputfor_o - converts int to octal
 * @n: integer to be checked
 * Return: output length
 */
int outputfor_o(unsigned int n)
{
	unsigned int pval, rem, oct, len, var;

	pval = 1;
	oct = 0;
		while (n)
		{
			rem = n % 8;
			oct = oct + (rem * pval);
			n = n / 8;
			pval = pval * 10;
		}
	outputfor_d(oct);
	var = oct;
	len = 0;
	do
	{
		var /= 10;
		len++;
	}
	while (var != 0);
	return (len);
}
