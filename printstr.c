#include "main.h"

/**
 * printstr - outputs a string
 * @str: array of characters
 * Return: number of character printed
*/

int printstr(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		counter++;
		str++;
	}
	return (counter);
}
