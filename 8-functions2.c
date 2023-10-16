
/**
 * input_long_oct - calculates a long octal number
 *
 * @bin: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *input_long_oct(char *bin, char *oct)
{
	int n, i, j, m, max_size;

	oct[22] = '\0';
	for (i = 63, m = 21; i >= 0; i--, m--)
	{
		if (i > 0)
			max_size = 4;
		else
			max_size = 1;
		for (n = 0, j = 1; j <= max_size; j *= 2, i--)
			n = ((bin[i] - '0') * j) + n;
		i++;
		oct[m] = n + '0';
	}
	return (oct);
}