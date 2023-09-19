#include "main.h"

/**
 * print_string - prints a string to the stdout
 * @input_str: the string to be printed
 *
 * Return: length of the string
 */
int print_string(char *input_str)
{
	int str_len;

	for (str_len = 0; input_str[str_len] != '\0'; str_len++)
	{
		putchar(input_str[str_len]);
	}
	return (str_len);
}
