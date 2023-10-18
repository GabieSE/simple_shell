#include "s_g_shell.h"

/**
 * plus_num - a positive number
 * @strng: a string to be used
 * Return: 1 always (success)
 */
int plus_num(char *strng)
{
	int j;

	if (!strng)
		return (0);
	for (j = 0; strng[j]; j++)
	{
		if (strng[j] < '0' || strng[j] > '9')
			return (0);

	}
	return (1);

}

/**
 * _atoi - converts a str arg to an int
 * @strng: a string to be converted
 *
 * Return: 0 (success)
 */
int _atoi(char *strng)
{
	int j, nbr = 0;

	for (j = 0; strng[j]; j++)
	{
		nbr *= 10;
		nbr += (strng[j] - '0');
	}
	return (nbr);
}
