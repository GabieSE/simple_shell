s_g_cmdread.c

#include "s_g_shell.h"

/**
 * cmd_rd - a function that reads a command
 * Return: a string
 */
char *cmd_rd(void)
{
	char *ln = NULL;
	size_t length = 0;
	ssize_t z;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2)
	}
	z = getline(&ln, &length, stdin);

	if (z == -1)
	{
		free(ln);
		return (NULL);
	}
	return (ln);
}
