#include "main.h"

/**
 * ndfrees - frees a ptr and NULLs the address
 * @p: address of ptr
 * Return: 1 if freed otherwise 0.
*/

int ndfrees(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
