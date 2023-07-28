#include "main.h"

/**
 * printint - converts integer to string
 * @num: integer to be converted
 * Return: length of the string
 */
int printint(int num)
{
	char buffer[40];
	int i = 0, a = 0;
	int lessThan_zero = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return (i);
	}
	if (num < 0)
	{
		lessThan_zero = 1;
		num = -num;
	}
	while (num != 0)
	{
		buffer[i++] = '0' + num % 10;
		num /= 10;
	}
	if (lessThan_zero)
	{
		buffer[i++] = '-';
	}
	buffer[i] = '\0';

	while (a < i)
	{
		_putchar(buffer[i - 1]);
		i--;
	}
	return (i);
}

