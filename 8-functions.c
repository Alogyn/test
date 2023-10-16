#include "main.h"
/**
 * print_long_int - prints a long integer
 * @arg_list: input string
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_int(va_list arg_list, char *buffer, unsigned int index)
{
	long int number;
	unsigned long int n, temp_num, i, diviser, check_negative;

	number = va_arg(arg_list, long int);
	check_negative = 0;
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
 * print_long_dig - prints a long integer
 * @arg_list: input string
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_dig(va_list arg_list, char *buffer, unsigned int index)
{
	long int number;
	unsigned long int n, temp_num, i, diviser, check_negative;

	number = va_arg(arg_list, long int);
	check_negative = 0;
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
 * print_long_uns - prints a long unsigned integer
 * @arg_list: number to print
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_uns(va_list arg_list, char *buffer, unsigned int index)
{
	unsigned long int n, temp_num, i, diviser;

	n = va_arg(arg_list, unsigned long int);
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
 * print_long_oct - prints long decimal number in octal
 * @arg_list: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_oct(va_list arg_list, char *buffer, unsigned int index)
{
	long int number, i, check_negative, count, n;
	char *octal, *binary;

	number = va_arg(arg_list, long int);
	check_negative = 0;
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = input_to_binary(binary, number, check_negative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = input_to_long_oct(binary, octal);
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
 * print_long_hexa - prints a long decimal in hexa
 * @arg_list: input string
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed
 */
int print_long_hexa(va_list arg_list, char *buffer, unsigned int index)
{
	long int number, i, check_negative, count, n;
	char *hexa, *binary;

	number = va_arg(arg_list, long int);
	check_negative = 0;
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = input_to_binary(binary, number, check_negative, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = input_to_hexa(binary, hexa, 0, 16);
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

/**
 * print_long_uhexa - prints a long decimal in hexa
 * @arg_list: The character to print
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed
 */
int print_long_uhexa(va_list arg_list, char *buffer, unsigned int index)
{
	long int number, i, check_negative, count, n;
	char *hexa, *binary;

	number = va_arg(arg_list, long int);
	check_negative = 0;
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = input_to_binary(binary, number, check_negative, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = input_to_hexa(binary, hexa, 1, 16);
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

/**
 * input_to_long_oct - calculates a long octal number
 *
 * @bin: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *input_to_long_oct(char *bin, char *oct)
{
	int n, i, j, m, max_size;

	oct[22] = '\0';
	for (i = 63, m = 21; i >= 0; i--, m--)
	{
		if (i > 0)
			max_size = 4;
		else
			max_size = 1;
		for (n = 0, j = 1; j <= max_size; j *= 2, i--)
			n = ((bin[i] - '0') * j) + n;
		i++;
		oct[m] = n + '0';
	}
	return (oct);
}