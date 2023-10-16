#include "main.h"

/**
 * print_address - Prints the address of a input
 *
 * @arg_list: Input integers argument (int)
 * @buffer: Buffer array (char)
 * @index: Number of buffer index (int)
 *
 * Return: The length of address
 */

int print_address(va_list arg_lisr, char *buffer, unsigned int index)
{
	void *address;
	long int number;
	int i, count, n, check_negative;
	char *hexa, *binary;
	char none[] = "(nil)";

	address = (va_arg(arg_lisr, void *));
	if (address == NULL)
	{
		for (i = 0; none[i]; i++)
			index = _puts(buffer, none[i], index);
		return (5);
	}
	number = (intptr_t)address;
	check_negative = 0;
	if (number < 0)
	{
		number = (number * -1) - 1;
		check_negative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = input_to_binary(binary, number, check_negative, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = input_to_hexa(binary, hexa, 0, 16);
	index = _puts(buffer, '0', index);
	index = _puts(buffer, 'x', index);
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
	return (count + 2);
}

/**
  * print_space - Prints integers with ' ' flag
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an integer output
 */

int print_space_int(va_list arg_list, char *buffer, unsigned int index)
{
	int number;
	unsigned int n, temp_num, i, diviser;

	number = va_arg(arg_list, int);
	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
	}
	else
	{
		n = number;
		index = _puts(buffer, ' ', index);
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
  * print_space_dig - Prints digits with ' ' flag
  *
  * @arg_list: Input digits argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an digit output
 */

int print_space_dig(va_list arg_list, char *buffer, unsigned int index)
{
	int number;
	unsigned int n, temp_num, i, diviser;

	number = va_arg(arg_list, int);
	if (number < 0)
	{
		n = number * -1;
		index = _puts(buffer, '-', index);
	}
	else
	{
		n = number;
		index = _puts(buffer, ' ', index);
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