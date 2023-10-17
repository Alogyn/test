#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to hold information about the format specifier
typedef struct {
    char flag;
    int width;
} FormatSpecifier;

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

FormatSpecifier parse_specifier(const char *format, int *index) {
    FormatSpecifier specifier = {0, 0};

    // Check for zero flag
    if (format[*index] == '0') {
        specifier.flag = '0';
        (*index)++;
    }

    // Parse width if present
    while (is_digit(format[*index])) {
        specifier.width = specifier.width * 10 + (format[*index] - '0');
        (*index)++;
    }

    return specifier;
}

int zero_flag(va_list args, char *buf, unsigned int index, FormatSpecifier specifier) {
    // Get the integer argument from the argument list
    int num = va_arg(args, int);
    
    // Calculate the number of zeros to pad
    int zeros = specifier.width - snprintf(NULL, 0, "%d", num);
    
    // Print zeros
    for (int i = 0; i < zeros; ++i) {
        buf[index++] = '0';
    }

    // Print the number
    index += snprintf(buf + index, specifier.width + 1, "%d", num);
    
    return index;
}

// Modify your _printf function to incorporate the zero_flag function

int _printf(const char *format, ...) {
    // ... (your existing code)

    int i = 0;
    FormatSpecifier specifier;

    // ... (your existing code)

    while (format[i]) {
        // Check for format specifier
        if (format[i] == '%') {
            // Parse the specifier including the zero flag and width
            specifier = parse_specifier(format, &i);

            // Call zero_flag function when zero flag is found
            if (specifier.flag == '0') {
                char_counter += zero_flag(arg_list, temp, index, specifier);
            } else {
                // Handle other flags or no flags
                // ...
            }
        } else {
            // Handle non-specifier characters
            // ...
        }
        // ... (your existing code)
    }

    // ... (your existing code)
}