#include "main.h"

/**
 * l_lenght - determines lenght of linked list
 * @p: ptr
 * Return: size of list
*/

size_t l_lenght(const str_t *p)
{
	size_t i = 0;

	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * list_str - returns an arrays of str
 * @h: adreess ptr
 * Return: array of str
*/

char **list_str(str_t *h)
{
	str_t *nd = h;
	size_t i = l_lenght(h), j;
	char **strs;
	char *str;

	if (!h || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; nd; nd = nd->next, i++)
	{
		atr = malloc(_strlen(nd->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, nd->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * pr_list - prints all elements of a str_t
 * @p: ptr
 * Return: size of list
*/

size_t pr_list(const str_t *p)
{
	size_t i = 0;

	while (p)
	{
		_puts(conv_num(p->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_putchar(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * nd_strt - returns nd whose str strt
 * @nd: ptr
 * @str: str
 * @c: crctr
 * Return: match nd or null
*/

str_t *nd_strt(str_t *nd, char *str, char c)
{
	char *ptr = NULL;

	while (nd)
	{
		ptr = strts(nd->str, str);
		if (ptr && ((c == -1) || (*ptr == c))
				return (nd);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * get_nd_index - gets node index
 * @h: adress head
 * @nd: node
 *
 * Return: index of node
*/

ssize_t get_nd_index(str_t *h, str_t *nd)
{
	size_t i = 0;

	while (h)
	{
		if (h == nd)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
