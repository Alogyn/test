#include "main.h"

/**
  * print_plus_int - Prints integers with '+' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of integers 
 */

int print_plus_int(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	unsigned int n, temp_num, i, diviser;

	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
	}
	else
	{
		n = number;
		index = _puts(buffer, '+', index);
	}
	temp_num = n;
	diviser = 1;
	while (temp_num > 9)
	{
		diviser *= 10;
		temp_num /= 10;
	}
	for (i = 0; diviser > 0; diviser /= 10, i++)
	{
		index = _puts(buffer, ((n / diviser) % 10) + '0', index);
	}
	return (i + 1);
}

/**
  * print_plus_dig - Prints digits with '+' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of digits 
 */

int print_plus_dig(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	unsigned int n, temp_num, i, diviser;

	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
	}
	else
	{
		n = number;
		index = _puts(buffer, '+', index);
	}
	temp_num = n;
	diviser = 1;
	while (temp_num > 9)
	{
		diviser *= 10;
		temp_num /= 10;
	}
	for (i = 0; diviser > 0; diviser /= 10, i++)
	{
		index = _puts(buffer, ((n / diviser) % 10) + '0', index);
	}
	return (i + 1);
}

/**
  * print_zero_oct - Prints octal with '#' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an octal output
 */

int print_zero_oct(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	int i = 0, check_negative = 0, count, n = 0;
	char *octal, *binary;

	if (number == 0)
	{
		index = _puts(buffer, '0', index);
		return (1);
	}
	if (number < 0)
	{
		number = (number * -1) - 1;
		check_negative = 1;
	}
	index = _puts(buffer, '0', index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = input_to_octal(binary, octal);
	for (count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && n == 0)
			n = 1;
		if (n)
		{
			index = _puts(buffer, octal[i], index);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}

/**
  * print_zero_hexa - Prints hexadicimal in lowercase with '#' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an hexadicimal output
 */

int print_zero_hexa(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	int i = 0, check_negative = 0, count, n = 0;
	char *hexa, *binary;

	if (number == 0)
	{
		index = _puts(buffer, '0', index);
		return (1);
	}
	if (number < 0)
	{
		number = (number * -1) - 1;
		check_negative = 1;
	}
	index = _puts(buffer, '0', index);
	index = _puts(buffer, 'x', index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = input_to_hexa(binary, hexa, 0, 8);
	for (count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && n == 0)
			n = 1;
		if (n)
		{
			index = _puts(buffer, hexa[i], index);
			count++;
		}
	}
	free(binary);
	free(hexa);
	return (count + 2);
}

/**
  * print_zero_uhexa - Prints hexadicimal in uppercase with '#' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an hexadicimal output
 */

int print_zero_uhexa(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	int i = 0, check_negative = 0, count, n = 0;
	char *hexa, *binary;

	if (number == 0)
	{
		index = _puts(buffer, '0', index);
		return (1);
	}
	if (number < 0)
	{
		number = (number * -1) - 1;
		check_negative = 1;
	}
	index = _puts(buffer, '0', index);
	index = _puts(buffer, 'X', index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = input_to_hexa(binary, hexa, 1, 8);
	for (count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && n == 0)
			n = 1;
		if (n)
		{
			index = _puts(buffer, hexa[i], index);
			count++;
		}
	}
	free(binary);
	free(hexa);
	return (count + 2);
}