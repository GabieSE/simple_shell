#include "s_g_shell.h"
/**
 * main - ENTRY POINT
 * @argc: it counts num of args passed on cmd
 * @av: Array of arguments passed on cmd
 * Return: 0 (success).
 */
int main(int argc, char **av)
{
	char *ln = NULL, **cmd = NULL;
	int sttus = 0, indx = 0;
	(void) argc;

	while (1)
	{
		ln = cmd_rd();
		if (ln == NULL) /*end-of-file*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (sttus);
		}
		indx++;

		cmd = tknze(ln);

		if (!cmd)
			continue;

		if (inbuilts(cmd[0]))

			builtn_hdl(cmd, av, &sttus, indx);

		else

			sttus = s_g_exec(cmd, av, indx);
	}
}
