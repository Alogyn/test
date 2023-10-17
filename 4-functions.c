#include "main.h"

/**
  * _puts - concatenates the buffer array
  *
  * @buffer: Buffer array (char)
  * @c: Input character (char)
  * @index: Number of buffer index
  *
  * Return: The number of buffer index
  */

unsigned int _puts(char *buffer, char c, unsigned int index)
{
	if (index == 1024)
	{
		_putchar(buffer, index);
		index = 0;
	}
	buffer[index] = c;
	index++;
	return (index);
}

/**
  * _putchar - prints buffer
  *
  * @buffer: buffer pointer
  * @index: number of bytes to print
  *
  * Return: number of bytes printed.
  */

int _putchar(char *buffer, unsigned int index)
{
	return (write(1, buffer, index));
}
