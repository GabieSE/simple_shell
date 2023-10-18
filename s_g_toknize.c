#include "s_g_shell.h"

/**
 * tknze - a function that tokenize a string
 * @ln: a string to be tokenized
 *
 * Return: a string
 */
char **tknze(char *ln)
{
	char *toknz = NULL, delimtr[] = " \t\n", *tpr = NULL;
	char **cmd = NULL;
	int cptr = 0, n = 0;

	if (!ln)
		return (NULL);
	tpr = sduplic(ln);
	toknz = strtok(tpr, delimtr);
	if (toknz == NULL)
	{
		free(ln), ln  = NULL;
		free(tpr), tpr = NULL;
		return (NULL);
	}

	while (toknz)
	{
		cptr++;
		toknz = strtok(NULL, delimtr);
	}
	free(tpr), tpr = NULL;

	cmd = malloc(sizeof(char *) * (cptr + 1));

	if (!cmd)
	{
		free(ln), ln  = NULL;
		return (NULL);
	}
	toknz = strtok(ln, delimtr);

	while (toknz)
	{
		cmd[n] = sduplic(toknz);
		toknz = strtok(NULL, delimtr);
		n++;
	}
	free(ln), ln = NULL;
	cmd[n] = NULL;
	return (cmd);
}
