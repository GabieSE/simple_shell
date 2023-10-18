#include "s_g_shell.h"

/**
 * sduplic - a function that duplicates a str
 * @strng: a string to be duplicated
 * Return: a ptr
 */
char *sduplic(const char *strng)
{
	char *ptrnm;
	int j, length = 0;

	if (strng == NULL)
		return (NULL);
	while (*strng != '\0')
	{
		length++;
		strng++;
	}
	strng = strng - length;
	ptrnm = malloc(sizeof(char) * (length + 1));
	if (ptrnm == NULL)
		return (NULL);
	for (j = 0; j <= length; j++)
		ptrnm[j] = strng[j];
	return (ptrnm);
}

/**
 * scomp - a function that compares 2 strings
 * @str1: string 1 to be comp
 * @str2: string 2
 * Return: an integer
 */
int scomp(char *str1, char *str2)
{
	int comp;

	comp = (int)*str1 - (int)*str2;

	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		comp = (int)*str1 - (int)*str2;
	}
	return (comp);
}

/**
 * slength - a function that calculate the len
 * of string
 * @t: a string to be calculated
 * Return: nber of calculated strs
 */
int slength(char *t)
{
	int length = 0;

	while (t[length])
		length++;
	return (length);
}

/**
 * sconcat - a function that concatenate strings
 * @destin: defines a destination
 * @source: defines where concat occur
 * Return: destination
 */
char *sconcat(char *destin, char *source)
{
	char *c = destin;

	while (*c)
		c++;
	while (*source)
	{
		*c = *source;
		c++;
		source++;
	}
	*c = *source;
	return (destin);
}

/**
 * scopy - a function that copies from on str to another
 * @destin: a copy of source
 * @source: a string to be copied
 * Return: a string
 */
char *scopy(char *destin, char *source)
{
	int j = 0;

	while (source[j])
	{
		destin[j] = source[j];
		j++;

	}
	destin[j] = 0;
	return (destin);
}
