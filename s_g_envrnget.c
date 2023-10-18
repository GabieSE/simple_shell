#include "s_g_shell.h"

/**
 * _envrnget - a func that gets envs
 * @varnm: a variable
 *
 * Return: returns a string
 */
char *_envrnget(char *varnm)
{
	char *tpry, *lck, *num, *envrn;
	int j;

	for (j = 0; environ[j]; j++)
	{
		tpry = sduplic(environ[j]);
		lck = strtok(tpry, "=");
		if (scomp(lck, varnm) == 0)
		{
			num = strtok(NULL, "\n");
			envrn = sduplic(num);
			free(tpry);
			return (envrn);
		}
		free(tpry), tpry = NULL;
	}
	return (NULL);
}
