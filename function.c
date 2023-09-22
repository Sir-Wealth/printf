#include "main.h"

int _printf(const char *format, ...);
/**
 * _printf - print function.
 * @format: a variable
 * Return: C_print
 */

int _printf(const char *format, ...)
{
	int c_print = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == 0) || format[0] == 0)
		return (1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			c_print++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				c_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				c_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				c_print += str_len;
			}
		}
		format++;
	}
	va_end(args);

	return (c_print);
}
