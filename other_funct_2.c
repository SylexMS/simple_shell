#include "main.h"

/**
 * _erroratoi - converts a str to an int
 * @c: str
 * Return: 0 if no number in str
*/

int _erroratoi(char *c)
{
	int i = 0;
	unsigned long int res = 0;

	if (*c == '+')
		c++;
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			res *= 10;
			res += (c[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * pr_err - prints an error mess
 * @info: info
 * @str: str
 * Return: 0 if no number in str
*/

void pr_err(info_t *info, char *str)
{
	_iputs(info->fname);
	_iputs(": ");
	pr_d(info->line_count, STDERR_FILLENO);
	_iputs(": ");
	_iputs(info->argv[0]);
	_iputs(": ");
	_iputs(str);
}

/**
 * pr_d - funct prints a decimal int number
 * @ipt: input
 * @f: file description
 * Return: number of crctr
*/

int pr_d(int ipt, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs, curr;

	if (f == STDERR_FILENO)
		__putchar = _iputchar;
	if (ipt < 0)
	{
		_abs = -ipt;
		__putchar('-');
		count++;
	}
	else
		_abs = ipt;
	curr = _abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs / i)
		{
			__putchar('0' + curr / i);
			count++;
		}
		curr %= i;
	}
	__putchar('0' + curr);
	count++;

	return (count);
}

/**
 * conv_num - converter funct a clone of itioa
 * @n: number
 * @bs: base
 * @fg: fllag
 * Return: str
*/

char *conv_num(long int n, int bs, int fg)
{
	static char *arr;
	static char buff[50];
	charr sg = 0;
	char *p;
	unsigned long nm = n;

	if (!(fg & CONVERT_UNSIGNED) && num < 0)
	{
		nm = -n;
		sg = '-';

	}
	arr = fg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do {
		*--p = arr[nm % bs];
		nm /= bs;
	} while (nm != 0);

	if (sg)
		*--p = sg;
	return (p);
}

/**
 * rm_comments - replaces first instance of # whith 0
 * @buf: adress of str
 * Return: always 0 success
*/

void rm_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
