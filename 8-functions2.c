#include "main.h"

/**
 * input_long_oct - calculates a long octal number
 *
 * @bin: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */

char *input_long_oct(char *bin, char *oct)
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


/**
  * print_short_uhexa - Prints short hexadicimal
  *
  * @arg_list: Input hexadicimal argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of hexadicimal output
  */

int print_short_uhexa(va_list arg_list, char *buffer, unsigned int index)
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
	hexa = input_to_hexa(binary, hexa, 1, 4);

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
 * input_short_oct - Calculates the short octal input
 *
 * @bin: Binary pointer (char)
 * @oct: octal pointer (char)
 *
 * Return: Octal
 */
char *input_short_oct(char *bin, char *oct)
{
	int n, i, j, m, max_size;

	oct[6] = '\0';
	for (i = 15, m = 5; i >= 0; i--, m--)
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
/**
  * print_long_uhexa - Prints long hexadicimal
  *
  * @arg_list: Input hexadicimal argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of hexadicimal output
  */

int print_long_uhexa(va_list arg_list, char *buffer, unsigned int index)
{
	long int number = va_arg(arg_list, long int);
	long int i, check_negative = 0, count, n;
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