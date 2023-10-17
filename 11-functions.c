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