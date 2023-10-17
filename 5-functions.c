#include "main.h"

/**
  * print_unsigned_str - Prints the non-printable characters or string
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The lenh of a non-printable 'char' or 'str'
  */

int print_unsigned_str(va_list arg_list, char *buffer, unsigned int index)
{
	unsigned char *str = va_arg(arg_list, unsigned char *);
	int count = 0;
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer[index++] = '\\';
			buffer[index++] = 'x';
			buffer[index++] = (str[i] / 16) + ((str[i] / 16 > 9) ? 'A' - 10 : '0');
			buffer[index++] = (str[i] % 16) + ((str[i] % 16 > 9) ? 'A' - 10 : '0');
			count += 4;
		}
		else
		{
			buffer[index++] = str[i];
			count++;
		}
	}
	return (count);
}

/**
  * input_to_hexa - Prints hexadicimal numbers
  *
  * @bin: Input Binary pointer (char)
  * @hex: Input Hexadicimal pointer (char)
  * @check_upper: Checks the format of the input (int)
  * @max_size: Max size for the hexadicimal output(int)
  *
  * Return: the length of a hexadicimal numbers
  */

char *input_to_hexa(char *bin, char *hex, int check_upper, int max_size)
{
	int n, i, j, letter_change;

	hex[max_size] = '\0';
	if (check_upper)
		letter_change = 55;
	else
		letter_change = 87;
	for (i = (max_size * 4) - 1; i >= 0; i--)
	{
		for (n = 0, j = 1; j <= 8; j *= 2, i--)
			n = ((bin[i] - '0') * j) + n;
		i++;
		if (n < 10)
			hex[i / 4] = n + 48;
		else
			hex[i / 4] = n + letter_change;
	}
	return (hex);
}
