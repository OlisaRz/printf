#include <stddef.h>
#include <stdlib.h>
#include "main.h"
/**
 * outputfor_b - changes unsigned int to binary
 * @n: integer parameter
 * Return: output length
 */
int outputfor_b(unsigned int n)
{
	long int bin, rem, pval, var, len;

	pval = 1;
	bin = 0;
	while (n)
	{
		rem = n % 2;
		n /= 2;
		bin += (rem * pval);
		pval *= 10;
	}
	outputfor_d(bin);
	var = bin;
	len = 0;
	do
	{
		var /= 10;
		len++;
	}
	while (var != 0);
	return (len);
}
