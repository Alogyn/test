#include "main.h"

/**
  * _printf - Prints the input format
  *
  * @format: Input data arguments (const char)
  *
  * Return: The length of 'format'
  */

int _printf(const char *format, ...)
{
	unsigned int index = 0, char_counter = 0, i = 0;
	va_list arg_list;
	int (*funct)(va_list, char *, unsigned int);
	char *temp;

	va_start(arg_list, format), temp = malloc(sizeof(char) * 1024);
	if (!format || !temp || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	_putchar(temp, index), free(temp), va_end(arg_list);
				return (-1);
			}
			else
			{	funct = specifier_functions(format, i + 1);
				if (funct == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					_puts(temp, format[i], index), len++, i--;
				}
				else
				{
					len += funct(arg_list, temp, index);
					i += specifiers_counter(format, i + 1);
				}
			} i++;
		}
		else
			_puts(temp, format[i], index), len++;
		for (index = len; index > 1024; index -= 1024)
			;
	}
	_putchar(temp, index), free(temp), va_end(arg_list);
	return (len);
}
