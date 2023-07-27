#include "main.h"

/**
 * _node - adds a node to the start of list
 * @h: adress ptr
 * @str: str
 * @n: number
 * Return:size of list
*/

str_t *_node(str_t **h, const char *str, int n)
{
	str_t *new_h;

	if (!h)
		return (NULL);
	new_h = malloc(sizeof(str_t));
	if (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(str_t));
	new_h->n = n;
	if (str)
	{
		new_h->str == _strdup(str);
		if (!new_h->str)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *h;
	*h = new_h;
	return (new_h);
}

/**
 * pr_str - prints onlt str
 * @p: ptr
 * Return: size of list
*/

size_t  pr_str(const str_t *p)
{
	sz_t i = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * rm_node - delets node
 * @h: head adress
 * @in: index
 * Return: 1 on success, 0 in failure
*/

int rm_node(str_t **h, unsigned int in)
{
	str_t *nd, *sec_nd;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (in)
	{
		nd = *h;
		*h = (*h)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *h;
	while (nd)
	{
		if (i == in)
		{
			sec_nd->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		i++;
		sec_nd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * list_free - frees all nodes of a list
 * @h: ptr adrress
*/

void list_free(str_t **h)
{
	str_t *nd, *sec_nd, *head;

	if (!h || !*head)
		return;
	head = *h;
	nd = head;
	while (nd)
	{
		sec_nd = node->next;
		free(nd->str);
		free(nd);
		nd = sec_nd;
	}
	*h = NULL;
}
