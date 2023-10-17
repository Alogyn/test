#include "main.h"

/**
  * print_octal - Convertes and prints an integer
  * to octal
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an octal numbers
  */

int print_octal(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
	int number = va_arg(arg_list, int);
	int i = 0, check_negative = 0, count, j = 0;
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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = input_to_octal(binary, octal);
	for (count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && j == 0)
			j = 1;
		if (j)
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
  * input_to_octal - Prints octal numbers
  *
  * @bin: Input Binary pointer (char)
  * @oct: Input Octal pointer (char)
  *
  * Return: The length of an octal numbers
  */

char *input_to_octal(char *bin, char *oct)
{
	int n, i, j, k, max_size;

	oct[11] = '\0';
	for (i = 31, k = 10; i >= 0; i--, k--)
	{
		if (i > 1)
			max_size = 4;
		else
			max_size = 2;
		for (n = 0, j = 1; j <= max_size; j *= 2, i--)
			n = ((bin[i] - '0') * j) + n;
		i++;
		oct[k] = n + '0';
	}
	return (oct);
}

/**
  * print_unsigned - Prints an unsigned int
  *
  * @arg_list: number to print
  * @buffer: buffer pointer
  * @index: index for buffer pointer
  *
  * Return: The length of an integer
  */

int print_unsigned(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
	unsigned int number = va_arg(arg_list, unsigned int);
	unsigned int i = 0, temp, diviser = 1;

	temp = number;
	while (temp > 9)
	{
		diviser *= 10;
		temp /= 10;
	}
	for (; diviser > 0; diviser /= 10, i++)
	{
		index = _puts(buffer, ((number / diviser) % 10) + '0', index);
	}
	return (i);
}

/**
  * print_lower_hexa - Convertes and prints an integer
  * to lowercase hexadicimal
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an hexadicimal numbers
  */

int print_lower_hexa(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
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
	return (count);
}

/**
  * print_upper_hexa - Convertes and prints an integer
  * to uppercase hexadicimal
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of an hexadicimal numbers
  */

int print_upper_hexa(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
	int number = va_arg(arg_list, int);
	int i, check_negative = 0, count, n;
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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = input_to_hexa(binary, hexa, 1, 8);
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
