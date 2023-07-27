#include "main.h"

/**
 * _strcpy - copies a str
 * @ds: dest
 * @src: source
 * Return: ptr
*/

char *_strcpy(char *ds, char *src)
{
	int i = 0;

	if (ds == src || src == 0)
		return (ds);
	while (src[i])
	{
		ds[i] = src[i];
		i++;
	}
	ds[i] = 0;
	return (ds);
}

/**
 * _strdup - duplicates a str
 * @str: str
 * Return: ptr
*/

char *_strdup(const char *str)
{
	int len = 0;
	char *rt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	rt = malloc(sizeof(char) * (len + 1));
	if (!rt)
		return (NULL);
	for (len++; len--)
		rt[len] = *--str;
	return (rt);
}

/**
 * puts - prints an input str
 * @str: str
*/

void puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes crctr s to stdout
 * @s:the crctr
 * Return: 1 on success -1 on error
*/

int _putchar(char s)
{
	static int i;
	static char buf[WR_BUF_SIZE];

	if (s == BUF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buf[i++] = s;
	return (1);
}


