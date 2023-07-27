#include "main.h"

/**
 * _iputs - prints ipt str
 * @str: strr
*/

void _iputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_iputchar(str[i]);
		i++;
	}
}

/**
 * _iputchar - writes crctr c to stderr
 * @c: crctr
 * Return: 1 on success, 0 otherwise
*/

int _iputchar(char c)
{
	static int i;
	static char buf[WR_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfile -prints ipt str
 * @str: str
 * @f: fille
 * Return: numbers of char
*/

int _putsfile(char *str, int f)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putsfile(*str++, f);
	}
	return (i);
}
