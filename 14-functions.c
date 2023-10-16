#include "main.h"

/**
 * print_rot - writes the str in ROT13
 * @arg_list: input string
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rot(va_list arg_list, char *buffer, unsigned int index)
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
