#include "main.h"

/**
  * print_reverse - Prints string in reverse
  *
  * @arg_list: Input integers argument (int)
  * @buffer: Buffer array (char)
  * @index: Number of buffer index (int)
  *
  * Return: The length of a reverse numbers
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
