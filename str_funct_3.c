#include "main.h"

/**
 * _strcpy - copies a str
 * @ds: the ds
 * @src: source
 * @am: amount of crctr to be copied
 * Return: str
*/

char *_strcpy(char *ds, char *src, int am)
{
	int i, d;
	char *c = ds;

	i = 0;
	while (src[i] != '\0' && i < am - 1)
	{
		ds[i] = src[i];
		i++;
	}
	if (i < am)
	{
		d = i;
		while (d < am)
		{
			ds[d] = '\0';
			d++;
		}
	}
	return (c);
}

/**
 * _strncat - concates two str
 * @src: the source
 * @ds: dest
 * @am: the amount
 * Return: str
*/

char *_strncat(char *ds, char *src, int am)
{
	int i, d;
	char *c = ds;

	i = 0;
	d = 0;
	while (ds[i] != '\0')
		i++;
	while (src[i] != '\0' && d < am)
	{
		ds[i] = src[i];
		i++;
		d++;
	}
	if (d < am)
		ds[i] = '\0';
	return (c);
}

/**
 * _strchr - locates a crctr in a str
 * @str: str
 * @c: crctr
 * Return: ptr
*/

char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
