#include "main.h"

/**
  * specifiers_counter - Checks and count the number of specifiers format
  *
  * @s: Input string argument (char)
  * @index: Number of buffer index (int)
  *
  * Return: Number of specifiers
  */

int specifiers_counter(const char *s, int index)
{
	int i = 0, j = 0, n;
	specif_t founder[] = {
		{"c", print_character}, {"s", print_string}, {"%", print_percent},
		{"i", print_integer}, {"d", print_digit}, {"b", print_binary},
		{"u", print_unsigned}, {"o", print_octal}, {"x", print_lower_hexa},
		{"X", print_upper_hexa}, {"S", print_unsigned_str}, {"p", print_address},
		{"+i", print_plus_int}, {"+d", print_plus_dig}, {"+u", print_unsigned},
		{"+o", print_octal}, {"+x", print_lower_hexa}, {"+X", print_upper_hexa},
		{" +i", print_plus_int}, {" +d", print_plus_dig}, {"+ i", print_plus_int},
		{"+ d", print_plus_dig}, {" i", print_space_int}, {" d", print_space_dig},
		{" u", print_unsigned}, {" o", print_octal}, {" x", print_lower_hexa},
		{" X", print_upper_hexa}, {" %", print_percent}, {"#o", print_zero_oct},
		{"#x", print_zero_hexa}, {"#X", print_zero_uhexa}, {"#i", print_integer},
		{"#d", print_digit}, {"#u", print_unsigned}, {"li", print_long_int},
		{"ld", print_long_dig}, {"lu", print_long_uns}, {"lo", print_long_oct},
		{"lx", print_long_hexa}, {"lX", print_long_uhexa}, {"hi", print_short_int},
		{"hd", print_short_dig}, {"hu", print_short_uns}, {"ho", print_short_oct},
		{"hx", print_short_hexa}, {"hX", print_short_uhexa}, {"l", print_percent},
		{"h", print_percent}, {"R", print_rot}, {"r", print_reverse},
		{"0", print_zero_flag}, {"-", print_minus_flag}, {".", print_precision},
		{"*", print_width}, {NULL, NULL},
	};

	n = index;
	while (founder[i].type_format)
	{
		if (s[index] == founder[i].type_format[j])
		{
			if (founder[i].type_format[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = n;
		}
	}
	return (j);
}

/**
  * specifier_func - Checks ans selects the specifier format
  *
  * @s: Input string argument (char)
  * @index: Number of buffer index (int)
  *
  * Return: The pointer to function
  */
int (*specifier_func(const char *s, int index))(va_list, char *, unsigned int)
{
	int i = 0, j = 0, n;
	specif_t founder[] = {
		{"c", print_character}, {"s", print_string}, {"%", print_percent},
		{"i", print_integer}, {"d", print_digit}, {"b", print_binary},
		{"u", print_unsigned}, {"o", print_octal}, {"x", print_lower_hexa},
		{"X", print_upper_hexa}, {"S", print_unsigned_str}, {"p", print_address},
		{"+i", print_plus_int}, {"+d", print_plus_dig}, {"+u", print_unsigned},
		{"+o", print_octal}, {"+x", print_lower_hexa}, {"+X", print_upper_hexa},
		{" +i", print_plus_int}, {" +d", print_plus_dig}, {"+ i", print_plus_int},
		{"+ d", print_plus_dig}, {" i", print_space_int}, {" d", print_space_dig},
		{" u", print_unsigned}, {" o", print_octal}, {" x", print_lower_hexa},
		{" X", print_upper_hexa}, {" %", print_percent}, {"#o", print_zero_oct},
		{"#x", print_zero_hexa}, {"#X", print_zero_uhexa}, {"#i", print_integer},
		{"#d", print_digit}, {"#u", print_unsigned}, {"li", print_long_int},
		{"ld", print_long_dig}, {"lu", print_long_uns}, {"lo", print_long_oct},
		{"lx", print_long_hexa}, {"lX", print_long_uhexa}, {"hi", print_short_int},
		{"hd", print_short_dig}, {"hu", print_short_uns}, {"ho", print_short_oct},
		{"hx", print_short_hexa}, {"hX", print_short_uhexa}, {"l", print_percent},
		{"h", print_percent}, {"R", print_rot}, {"r", print_reverse},
		{"0", print_zero_flag}, {"-", print_minus_flag}, {".", print_precision},
		{"*", print_width}, {NULL, NULL},
	};

	n = index;
	while (founder[i].type_format)
	{
		if (s[index] == founder[i].type_format[j])
		{
			if (founder[i].type_format[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = n;
		}
	}
	return (founder[i].f);
}
