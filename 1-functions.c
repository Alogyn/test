#include "main.h"

/**
  * print_integer - Prints an integer
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of integers
  */

int print_integer(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	unsigned int num, num_stored, i, diviser, negative_checker = 0;

	if (number < 0)
	{
		num = number * - 1;
		index = _puts(buffer, '-', index);
		negative_checker = 1;
	}
	else
	{
		num = number;
	}

	num_stored = num;
	diviser = 1;

	while (num_stored > 9)
	{
		diviser *= 10;
		num_stored /= 10;
	}

	for (i = 0; diviser > 0; diviser /= 10, i++)
	{
		index = _puts(buffer, ((num / diviser) % 10) + '0', index);
	}
	return (i + negative_checker);
}

/**
  * print_digit - Prints a digit
  *
  * @arg_list: Input digits argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of digits
  */
int print_digit(va_list arg_list, char *buffer, unsigned int index)
{
	int number = va_arg(arg_list, int);
	unsigned int num, num_stored, i, diviser, negative_checker = 0;

	if (number < 0)
	{
		num = number * - 1;
		index = _puts(buffer, '-', index);
		negative_checker = 1;
	}
	else
	{
		num = number;
	}

	num_stored = num;
	diviser = 1;

	while (num_stored > 9)
	{
		diviser *= 10;
		num_stored /= 10;
	}

	for (i = 0; diviser > 0; diviser /= 10, i++)
	{
		index = _puts(buffer, ((num / diviser) % 10) + '0', index);
	}
	return (i + negative_checker);
}