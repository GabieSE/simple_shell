#include "s_g_shell.h"

/**
 * array_freed - a function that frees an array
 * @ptrarr: an array to be freed
 */
void array_freed(char **ptrarr)
{
	int k;

	if (!ptrarr)
		return;

	for (k = 0; ptrarr[k]; k++)
	{
		free(ptrarr[k]);
		ptrarr[k] = NULL;
	}
	free(ptrarr), ptrarr = NULL;
}

/**
 * errprt - a function that prints an error
 * @nom: a string to be printed as err
 * @commd: a string to be printed as err
 * @indx: an integer
 */
void errprt(char *nom, char *commd, int indx)
{
	char *idx_nm, message[] = ": not found\n";

	idx_nm = _itoa(indx);

	write(STDERR_FILENO, nom, slength(nom));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx_nm, slength(idx_nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, commd, slength(commd));
	write(STDERR_FILENO, message, slength(message));

	free(idx_nm);
}

/**
 * _itoa - converts an int into a string
 * @z: an int to be converted
 * Return: a string
 */
char *_itoa(int z)
{
	char  buffsz[30];
	int l = 0;

	if (z == 0)
		buffsz[l++] = '0';
	else
	{
		while (z > 0)
		{
			buffsz[l++] = (z % 10) + '0';
			z /= 10;
		}
	}
	buffsz[l] = '\0';
	str_rvrs(buffsz, l);

	return (sduplic(buffsz));
}
/**
 * str_rvrs - a function that reverses a string
 * @strng: a string to be reversed
 * @ln: length of a str
 */
void str_rvrs(char *strng, int ln)
{
	char tpry;
	int alph = 0;
	int omg = ln - 1;

	while (alph < omg)
	{
		tpry = strng[alph];
		strng[alph] = strng[omg];
		strng[omg] = tpry;
		alph++;
		omg--;
	}
}
