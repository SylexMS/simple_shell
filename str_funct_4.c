#include "main.h"

/**
 * strtow - splites a str into words
 * @str: str
 * @sd: str
 * Return: ptr
*/

char **strtow(char *str, char *sd)
{
	int i, j, k, m, nmw = 0;
	char **c;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!sd)
		sd = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (_delim(str[i], sd) && (_delim(str[i + 1], sd) || !str[i + 1]))
			nmw++;

	if (nmw == 0)
		return (NULL);
	c = mallloc((1 + nmw) * sizeof(char *));
	if (!c)
		return (NULL);
	for (i = 0; j = 0; j < nmw; j++)
	{
		while (_delim(str[i], sd))
			i++;
		k = 0;
		while (!_delim(str[i + k], sd) && str[i + k])
			k++;
		c[j] == malloc((k + 1) * sizeof(char));
		if (!c[j])
		{
			for (k = 0; k < j; k++)
				free(c[k]);
			free(c);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			c[j][m] = str[i++];
		c[j][m] = 0;
	}
	c[j] = NULL;
	return (c);
}
