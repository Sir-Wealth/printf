#include "main.h"

/**
 * _printf - prints output to the stdout
 * @format: a character string
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output
 * to the string)
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int count = 0, str_count = 0;
	va_list optional_args;

	if (format == NULL)
		return (-1);
	va_start(optional_args, format);

	for (; format[count] != '\0'; count++)
	{
		if (format[count] != '%')
			putchar(format[count]);
		else if (format[count] == '%')
		{
			format++;
			if (format[count] == '%')
			{
				putchar(format[count]);
				str_count++;
			}
			else if (format[count] == 'c')
			{
				char one_char = va_arg(optional_args, int);

				putchar(one_char);
				str_count++;
			}
			else if (format[count] == 's')
			{
				char *str = va_arg(optional_args, char *);

				str_count = print_string(str);
				str_count--;
			}
		}
		va_end(optional_args);
	}
	return ((str_count + count) - 1);
}
