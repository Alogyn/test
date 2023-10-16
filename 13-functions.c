#include "main.h"

/**
 * print_reverse - writes the str in reverse
 * @arg_list: input string
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_reverse(va_list arg_list, char *buffer, unsigned int index)
{
	char *str;
	unsigned int i;
	int j = 0;
	char none[] = "(llun)";

	str = va_arg(arg_list, char *);
	if (str == NULL)
	{
		for (i = 0; none[i]; i++)
			index = _puts(buffer, none[i], index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		index = _puts(buffer, str[j], index);
	}
	return (i);
}
