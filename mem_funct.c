#include "main.h"

/**
 * _memset - fills memory with a cons byte
 * @s: ptr
 * @bt: bytes to fill *s with
 * @am: amount
 * Return: ptr
*/

char *_memset(char *s, char bt, unsigned int am)
{
	unsigned int i;

	for (i = 0; i < am; i++)
		s[i] = bt;
	return (s);
}

/**
 * frees - frees a str of strs
 * @str: str
*/

void frees(char **str)
{
	char **a = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(a);
}

/**
 * _realloc - reallocates a block of mem
 * @p: ptr
 * @old_sz: byts size of bloxk
 * @new_sz: byts size of bloxk
 * Return: ptr
*/

void *_realloc(void *p, unsigned int old_sz, unsigned int new_sz)
{
	char *pp;

	if (!p)
		return (malloc(new_sz));
	if (!new_sz)
		return (free(p), NULL);
	if (new_sz == old_sz)
		return (p);

	pp = malloc(new_sz);
	if (!pp)
		return (NULL);

	old_sz = old_sz < new_sz ? old_sz : new_sz;
	while (old_sz--)
		pp[old_sz] = ((char *)p)[old_sz];
	free(p);
	return (pp);
}
