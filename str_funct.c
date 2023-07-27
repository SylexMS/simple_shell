#include "main.h"

/**
 * _strlen - returns the length of a str
 * @c: the str whose lenght to check
 * Return: int length of str
*/

int _strlen(char *c)
{
	int i = 0;

	if (!c)
		return (0);

	while (*c++)
		i++;
	return (i);
}

/**
 * _strcmp - performs two str
 * @c: first str
 * @d: seconde str
 * Return: negative or positive
 */

int _strcmp(char *c, char *d)
{
	while (*c && *d)
	{
		if (*c != *d)
			return (*c - *d);
		c++;
		d++;
	}
	if (*c == *d)
		return (0);
	else
		return (*c < *d ? -1 : 1);
}

/**
 * _strts - checks if needlw starst with haystack
 * @hy: str to search
 * @nd: needle
 * Return: address of next char of hy or NULL
*/

char *_strts(const char *hy, const char *nd)
{
	while (*nd)
		if (*nd++ != *hy++)
			return (NULL);
	return ((char *)hy);
}

/**
 * _strcat - concatenates two str
 * @ds: dest
 * @src: source buffer
 * Return: ptr
*/

char *_strcat(char *ds, char *src)
{
	char *rt = ds;

	while (*ds)
		ds++;
	while (*src)
		*ds++ = *src++;
	*ds = *src;
	return (rt);
}
