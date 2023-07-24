#include "main.h"
#include <stdarg.h>
/**
 * _printf -  produces output according to a format.
 * @format:  is a character string.
 *
 * Return:  the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list value;
	int count = 0;

	va_start(value, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char ch = va_arg(value, int);

				_putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(value, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(value);
	return (count);
}
