#include "main.h"
#include <stdarg.h>

/**
 * _itoa - converts integer to string
 * @num: integer to be converted
 * @buffer: pointer to store the conversion
 * Return: an length of the string
 */
int _itoa(int num, char *buffer)
{
	int i = 0, a = 0, b;
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
	b = i - 1;
	while (a < b)
	{
		char holder = buffer[a];

		buffer[a] = buffer[b];
		buffer[b] = holder;
		a++;
		b--;
	}
	return (i);
}
/**
 * _printf - output integers
 * @format: string parameter
 * Return: return 0
 */
int _printf(const char *format, ...)
{
	char buffer[40];
	int c;
	va_list num;

	va_start(num, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'i' || *format == 'd')
			{
				int number = va_arg(num, int);
				int length = _itoa(number, buffer);

				for (c = 0; c < length; c++)
				{
					_putchar(buffer[c]);
				}
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(num);
	return (0);
}
