#include "main.h"
#include <stdio.h>
/**
 * outputfor_d - prints integers
 * @n: integer to be checked
 * Return: number length
 */
int outputfor_d(int n)
{
	int count = 0;
	int divisor = 1;
	int num = n;

	if (n < 0)
	{
		outputfor_c('-');
		n = -n;
		count++;
	}
	while (num / 10 != 0)
	{
		divisor *= 10;
		num /= 10;
		count++;
	}
	do
	{
		int digit = n / divisor;
		outputfor_c(digit + '0');
		n %= divisor;
		divisor /= 10;
		count++;
	}
	while (divisor > 0);
	return count;
}
