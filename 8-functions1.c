#include "main.h"

/**
  * print_short_int - Prints short integers
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of integers output
  */

int print_short_int(va_list arg_list, char *buffer, unsigned int index)
{
	short int number = va_arg(arg_list, int);
	unsigned short int n, temp_num, i, diviser, check_negative = 0;

	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
		check_negative = 1;
	}
	else
	{
		n = number;
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
	return (i + check_negative);
}

/**
  * print_short_dig - Prints short digits
  *
  * @arg_list: Input digits argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of digits output
  */

int print_short_dig(va_list arg_list, char *buffer, unsigned int index)
{
	short int number = va_arg(arg_list, int);
	unsigned short int n, temp_num, i, diviser, check_negative = 0;

	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
		check_negative = 1;
	}
	else
	{
		n = number;
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
	return (i + check_negative);
}

/**
  * print_short_uns - Prints short unsigned characters
  *
  * @arg_list: Input digits argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of unsigned characters output
  */

int print_short_uns(va_list arg_list, char *buffer, unsigned int index)
{
	unsigned short int n, temp_num, i, diviser;

	n = va_arg(arg_list, unsigned int);

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
	return (i);
}

/**
  * print_short_oct - Prints short octal
  *
  * @arg_list: Input octal argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of octal output
  */

int print_short_oct(va_list arg_list, char *buffer, unsigned int index)
{
	short int number = va_arg(arg_list, int);
	short int i, check_negative = 0, count, n;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = input_to_binary(binary, number, check_negative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = input_short_oct(binary, octal);
	for (n = i = count = 0; octal[i]; i++)
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
	return (count);
}

/**
  * print_short_hexa - Prints short hexadicimal
  *
  * @arg_list: Input hexadicimal argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of hexadicimal output
  */

int print_short_hexa(va_list arg_list, char *buffer, unsigned int index)
{
	short int number = va_arg(arg_list, int);
	short int i, check_negative = 0, count, n;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = input_to_binary(binary, number, check_negative, 16);
	hexa = malloc(sizeof(char) * (4 + 1));
	hexa = input_to_hexa(binary, hexa, 0, 4);
	for (n = i = count = 0; hexa[i]; i++)
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
	return (count);
}
