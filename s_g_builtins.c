#include "s_g_shell.h"

/**
 * inbuilts - built-in cmds
 * @cmd: ptr par
 *
 * Return: an int
 */
int inbuilts(char *cmd)
{
	char *builtn[] = {
		"exit", "env", "setenv", "cd", NULL
	};      /*built-in cmds*/
	int x;

	for (x = 0; builtn[x]; x++)
	{
		if (scomp(cmd, builtn[x]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtn_hdl - a func that handles builtin cmds
 * @cmd: cmd to be passed
 * @av: array of args
 * @sttus: an integer
 * @indx: an index
 */
void builtn_hdl(char **cmd, char **av, int *sttus, int indx)
{
	(void) av;
	(void)indx;

	if (scomp(cmd[0], "exit") == 0)
		exit_func(cmd, av, sttus, indx);
	else if (scomp(cmd[0], "env") == 0)
		environ_prt(cmd, sttus);
}

/**
 * exit_func - a function that handles exit cmd
 * @cmd: cmd to be passed
 * @av: an array of args
 * @sttus: an integer
 * @indx: an index
 */
void exit_func(char **cmd, char **av, int *sttus, int indx)
{
	int vlue_x = (*sttus);
	char *idx_nm, message[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (plus_num(cmd[1]))
		{
			vlue_x = _atoi(cmd[1]);
		}
		else
		{
			idx_nm = _itoa(indx);
			write(STDERR_FILENO, av[0], slength(av[0]));/* prints out */
			write(STDERR_FILENO, ": ", 2); /* prints out a delim */
			write(STDERR_FILENO, idx_nm, slength(idx_nm));
			write(STDERR_FILENO, message, slength(message));
			write(STDERR_FILENO, cmd[1], slength(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx_nm);
			array_freed(cmd);
			(*sttus) = 2;
			return;
		}
	}

	array_freed(cmd);
	exit(vlue_x);
}

/**
 * environ_prt - prints environmets
 * @cmd: db pointer str
 * @sttus: an integer
 */
void environ_prt(char **cmd, int *sttus) /* a function that prints env */
{
	int y;

	for (y = 0; environ[y]; y++)
	{
		write(STDOUT_FILENO, environ[y], slength(environ[y])); /* printing out */
		write(STDOUT_FILENO, "\n", 1); /* printing out */
	}
	array_freed(cmd);
	(*sttus) = 0; /* successful */
}
