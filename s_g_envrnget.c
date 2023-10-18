#include "s_g_shell.h"

/**
 * _envrnget - a func that gets envs
 * @varnm: a variable
 *
 * Return: returns a string
 */
char *_envrnget(char *varnm)
{
	char *ptr, *lck, *num, *envrn;
	int j;

	for (j = 0; environ[j]; j++)
	{
		ptr = sduplic(environ[j]);
		lck = strtok(ptr, "=");
		if (scomp(lck, varnm) == 0)
		{
			num = strtok(NULL, "\n");
			envrn = sduplic(num);
			free(ptr);
			return (envrn);

		}
		free(ptr), ptr = NULL;
	}
	return (NULL);
}
