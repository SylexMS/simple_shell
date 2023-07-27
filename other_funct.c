#include "main.h"

/**
 * intctv - returns true is shell is intercative mode
 * @stc: struct adress
 * Return: 1 if intctv 0 otherwise
*/

int intctv(info_t *stc)
{
	return (isatty(STDIN_FILENO) && stc->readfd <= 2);
}

/**
 * _delim - checks if crctr is a delimer
 * @s: char
 * @de: delim
 * Return: 1 if true, 0 if false
*/

int _delim(char s, char *de)
{
	while (*de)
		if (*de++ == s)
			return (1);
	return (0);
}

/**
 * _alpha - checks for alphabet crctr
 * @s: crctr
 * Return: 1 if c is alpha, 0 otherwise
*/

int _alpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a str to an int
 * @c: str
 * Return: 0 if no number is str
*/

int _atoi(char *c)
{
	int i, sg = 1, fg = 0, otp;
	unsigned int res = 0;

	for (i = 0; c[i] != '\0' && fg != 2; i++)
	{
		if (c[i] == '-')
			sg *= -1;

		if (c[i] >= '0' && c[i] <= '9')
		{
			fg = 1;
			res *= 10;
			res += (c[i] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sg == -1)
		otp = -res;
	else
		otp = res;

	return (otp);
}
