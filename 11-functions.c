#include "main.h"

int print_plus_int(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
    int number = va_arg(arg_list, int);
    char temp[50];
    
    snprintf(temp, sizeof(temp), "%0*d", width, number);
    
    for (int i = 0; temp[i] != '\0'; ++i)
    {
        buffer[index++] = temp[i];
    }
    
    return (index);
}

int print_minus_flag(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
    int number = va_arg(arg_list, int);
    char temp[50];

    snprintf(temp, sizeof(temp), "%-*.*d", width, precision, number);

    index = _puts(buffer, temp, index);
    return index;
}

int print_precision(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
{
    int number = va_arg(arg_list, int);
    char temp[50];

    snprintf(temp, sizeof(temp), "%*.*d", width, precision, number);

    index = _puts(buffer, temp, index);
    return index;
}

int print_width(va_list arg_list, char *buffer, unsigned int index, int width, int precision, int minus_flag)
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
    return index;
}