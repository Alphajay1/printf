#include "main.h"

/**
 * _printf - printf function
 * @format: string to be printed
 * Return: On success- the number of charcter printed,
 * On error, -1 is returned
*/
int _printf(const char *format, ...)
{
	va_list value;
	int count = 0;

	va_start(value, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				count += printpercent('%');
			}
			else if (*format == 'c')
			{
				count += printchar(va_arg(value, int));
			}
			else if (*format == 's')
			{
				count += printstr(va_arg(value, char *));
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += printint(va_arg(value, int));
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(value);
	return (count);
}
