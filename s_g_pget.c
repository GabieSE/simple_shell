#include "s_g_shell.h"

/**
 * _pget - a func that gets a path
 * @commd: a cmd included in path
 * Return: a string
 */
char *_pget(char *commd)
{
	char *envpath, *cmd_fll, *dirtry;
	int j;
	struct stat st;

	for (j = 0; commd[j]; j++)
	{
		if (commd[j] == '/')
		{
			if (stat(commd, &st) == 0)
				return (sduplic(commd));
			return (NULL);

		}
	}

	envpath = _envrnget("PATH");
	if (!envpath)
		return (NULL);

	dirtry = strtok(envpath, ":");
	while (dirtry)
	{
		cmd_fll = malloc(slength(dirtry) + slength(commd) + 2);
		if (cmd_fll)
		{
			scopy(cmd_fll, dirtry);
			sconcat(cmd_fll, "/");
			sconcat(cmd_fll, commd);
			if (stat(cmd_fll, &st) == 0)
			{
				free(envpath);
				return (cmd_fll);
			}
			free(cmd_fll), cmd_fll = NULL;
			dirtry = strtok(NULL, ":");
		}
	}
	free(envpath);
	return (NULL);
}
