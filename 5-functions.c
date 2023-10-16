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
	unsigned char *str;
	char *hexa, *binary;
	unsigned int i, sum, n;

	str = va_arg(arg_list, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexa = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			index = _puts(buffer, '\\', index);
			index = _puts(buffer, 'x', index);
			n = str[i];
			binary = input_to_binary(binary, n, 0, 32);
			hexa = input_to_hexa(binary, hexa, 1, 8);
			index = _puts(buffer, hexa[6], index);
			index = _puts(buffer, hexa[7], index);
			sum += 3;
		}
		else
			index = _puts(buffer, str[i], index);
	}
	free(binary);
	free(hexa);
	return (i + sum);
}
