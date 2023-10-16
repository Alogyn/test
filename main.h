#ifndef MAIN_H
#define MAIN_H

/* Standard libreries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/* '_printf.c' function */
int _printf(const char *format, ...);

/* Task 0: Functions to print characters, strings and percent */
int print_character(va_list arg_list, char *buffer, unsigned int index);
int print_string(va_list arg_list, char *buffer, unsigned int index);
int print_percent(va_list __attribute__((unused)), char *, unsigned int);

/* Task 1: Functions to print integers and digits */
int print_integer(va_list arg_list, char *buffer, unsigned int index);
int print_digit(va_list arg_list, char *buffer, unsigned int index);

/* Task 2: Functions to convertes and prints integers to binary */
int print_binary(va_list arg_list, char *buffer, unsigned int index);
char *input_to_binary(char *binary, long int number, int check_negative, int max_size);

/* Task 3: Functions to convertes and prints integers to octal and unsigned integer */
int print_octal(va_list arg_list, char *buffer, unsigned int index);
char *input_to_octal(char *bin, char *oct);
int print_unsigned(va_list arg_list, char *buffer, unsigned int index);

/* Task 3: Functions to convertes and prints integers to upper and lower hexadicimal */
int print_lower_hexa(va_list arg_list, char *buffer, unsigned int index);
int print_upper_hexa(va_list arg_list, char *buffer, unsigned int index);
char *input_to_hexa(char *bin, char *hex, int check_upper, int max_size);

/* Task 4: Functions to minimises the use of 'write()' and prints the 'char' or 'str'*/
unsigned int _puts(char *buffer, char c, unsigned int index);
int _putchar(char *buffer, unsigned int index);

/* Task 5: Function to prints non printable values */
int print_unsigned_str(va_list arg_list, char *buffer, unsigned int index);

/* Task 6: Function to prints an andress */
int print_address(va_list a, char *buf, unsigned int index);

/* Task 7: Functions to prints an integers or digits with flag */
int print_plus_int(va_list arg_list, char *buffer, unsigned int index);
int print_plus_dig(va_list arg_list, char *buffer, unsigned int index);
int print_space_int(va_list arg_list, char *buffer, unsigned int index);
int print_space_dig(va_list arg_list, char *buffer, unsigned int index);
int print_zero_oct(va_list arg_list, char *buffer, unsigned int index);
int print_zero_hexa(va_list arg_list, char *buffer, unsigned int index);
int print_zero_uhexa(va_list arg_list, char *buffer, unsigned int index);

/* Task 8: Functions to prints data with length*/
int print_long_int(va_list arg_list, char *buffer, unsigned int index);
int print_long_dig(va_list arg_list, char *buffer, unsigned int index);
int print_long_uns(va_list arg_list, char *buffer, unsigned int index);
int print_long_oct(va_list arg_list, char *buffer, unsigned int index);
char *input_long_oct(char *bin, char *oct);
int print_long_hexa(va_list arg_list, char *buffer, unsigned int index);
int print_long_uhexa(va_list arg_list, char *buffer, unsigned int index);

int print_short_int(va_list arg_list, char *buffer, unsigned int index);
int print_short_dig(va_list arg_list, char *buffer, unsigned int index);
int print_short_uns(va_list arg_list, char *buffer, unsigned int index);
int print_short_oct(va_list arg_list, char *buffer, unsigned int index);
char *input_short_oct(char *bin, char *oct);
int print_short_hexa(va_list arg_list, char *buffer, unsigned int index);
int print_short_uhexa(va_list arg_list, char *buffer, unsigned int index);

/* Task 13: Function to prints the reversed input */
int print_reverse(va_list arg_list, char *buffer, unsigned int index);

/* Task 14: Function to prints rot13 encode */
int print_rot(va_list arg_list, char *buffer, unsigned int index);

/**
  * struct specif - struct specifier format
  *
  * @type_format: Input type format
  * @f: Input function pointer
  */
struct specif
{
	char *type_format;
	int (*f)(va_list, char *, unsigned int);
};

typedef struct specif specif_t;

/* '_putchar function' */
unsigned int _puts(char *buffer, char c, unsigned int index);
int _putchar(char *buffer, unsigned int index);

/* Functions to determine end send the function for a specifier */
int (*specifier_func(const char *s, int index))(va_list, char *, unsigned int);
int specifiers_counter(const char *s, int index);

#endif /* MAIN_H */
