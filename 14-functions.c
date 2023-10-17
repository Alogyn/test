#include "main.h"

/**
  * print_rot - Prints string in rot13 encoding
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of a rot13 numbers
  */

int print_rot(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
	char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char none[] = "(avyy)";

	str = va_arg(arg_list, char *);
	if (str == NULL)
	{
		for (i = 0; none[i]; i++)
			index = _puts(buffer, none[i], index);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; letter[j]; j++)
		{
			if (str[i] == letter[j])
			{
				k = 1;
				index = _puts(buffer, rot[j], index);
				break;
			}
		}
		if (k == 0)
			index = _puts(buffer, str[i], index);
	}
	return (i);
}
