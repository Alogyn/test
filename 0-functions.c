#include "main.h"

/**
  * print_character - Prints a single character
  *
  * @arg_list: Input argument character (char)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: Always 1 (Success)
  */

int print_character(va_list arg_list, char *buffer, unsigned int index)
{
	_puts(buffer, va_arg(arg_list, int), index);

	return (1);
}

/**
  * print_string - Prints a string of characters
  *
  * @arg_list: Input argument character (char)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: If success, 'i' the number of string characters,
  * '6' if 'NULL'
  */

int print_string(va_list arg_list, char *buffer, unsigned int index)
{
	char *str;
	unsigned int i = 0;
	char none[] = "(null)";

	str = va_arg(arg_list, char *);
	if (str == NULL)
	{
		while (none[i] != '\0')
		{
			index = _puts(buffer, none[i], index);
			i++;
		}
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		index = _puts(buffer, str[i], index);
		i++;
	}

	return (i);
}

/**
  * print_percent - Prints a percent sign
  *
  * to showw it as a percentage
  * @a: Input character (unused)
  * @buffer: Buffer array (char)
  * @i: Number of buffer index (int)
  *
  * Return: Always 1 (Success)
  */

int print_percent(va_list a __attribute__((unused)),
		char *buffer, unsigned int i)
{
	_puts(buffer, '%', i);

	return (1);
}
