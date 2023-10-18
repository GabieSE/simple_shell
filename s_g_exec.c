#include "s_g_shell.h"

/**
 * s_g_exec - a function that executes a command
 * @cmd: a command to be executed
 * @av: array of arguments
 * @indx: an integer
 * Return: returns an int
 */
int s_g_exec(char **cmd, char **av, int indx)
{
	char *cmd_fll;
	pid_t kid_pid;
	int sttus;

	cmd_fll = _pget(cmd[0]);
	if (!cmd_fll)
	{
		errprt(av[0], cmd[0], indx);
		array_freed(cmd);

		return (127);
	}

	kid_pid = fork();

	if (kid_pid == 0)
	{
		if (execve(cmd_fll, cmd, environ) == -1)
		{
			free(cmd_fll), cmd_fll = NULL;
			array_freed(cmd);
		}
	}
	else
	{
		waitpid(kid_pid, &sttus, 0);
		array_freed(cmd);
		free(cmd_fll), cmd_fll = NULL;
	}
	return (WEXITSTATUS(sttus));
}
