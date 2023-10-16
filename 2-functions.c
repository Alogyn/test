#include "main.h"

/**
  * print_binary - Convertes an integer to binary
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of a binary numbers
  */

int print_binary(va_list arg_list, char *buffer, unsigned int index)
{
	int number, count, i, j, check_negative;
	char *binary;

	number = va_arg(arg_list, int);
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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = input_to_binary(binary, number, check_negative, 32);
	j = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (j == 0 && binary[i] == '1')
			j = 1;
		if (j == 1)
		{
			index = _puts(buffer, binary[i], indec);
			count++;
		}
	}
	free(binary);
	return (count);
}

/**
  * input_to_binary - Prints binary numbers
  *
  * @binary: Input binary format (char)
  * @number: Input integers (long int)
  * @check_negative: Checks for negative number (int)
  * @max_size: Max size for the binary output(int)
  *
  * Return: The length of a binary numbers
  */

char *input_to_binary(char *binary, long int number, int check_negative, int max_size)
{
	int i;

	for (i = 0; i < max_size; i++)
		binary[i] = '0';
	binary[max_size] = '\0';
	for (i = max_size - 1; number > 1; i--)
	{
		if (number == 2)
			binary[i] = '0';
		else
			binary[i] = (number % 2) + '0';
		number /= 2;
	}
	if (number != 0)
		binary[i] = '1';
	if (check_negative)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}
