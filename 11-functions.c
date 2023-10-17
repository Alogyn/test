#include "main.h"

int print_zero_flag(va_list arg_list, char *buffer, unsigned int index)
{
    int number = va_arg(arg_list, int), i;
    char temp[50];
    
    snprintf(temp, sizeof(temp), "%0*d", width, number);
    
    for (i = 0; temp[i] != '\0'; ++i)
    {
        buffer[index++] = temp[i];
    }
    
    return (index);
}

int print_minus_flag(va_list arg_list, char *buffer, unsigned int index, int minus_flag)
{
    int number = va_arg(arg_list, int);
    char temp[50];

    snprintf(temp, sizeof(temp), "%-*.*d", width, precision, number);

    index = _puts(buffer, temp, index);
    return (index);
}

int print_precision(va_list arg_list, char *buffer, unsigned int index, int precision)
{
    int number = va_arg(arg_list, int);
    char temp[50];

    snprintf(temp, sizeof(temp), "%*.*d", width, precision, number);

    index = _puts(buffer, temp, index);
    return (index);
}

int print_width(va_list arg_list, char *buffer, unsigned int index, int width)
{
    char temp[50];
	
    snprintf(temp, sizeof(temp), "%d", va_arg(arg_list, int));
    
    int padding = width - strlen(temp);
    if (padding > 0) {
        for (int i = 0; i < padding; i++) {
            index = _puts(buffer, ' ', index);
        }
    }
    
    index = _puts(buffer, temp, index);
    return (index);
}