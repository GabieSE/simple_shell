#ifndef S_G_SHELL_H
#define S_G_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* allows us to interact with extenal sys calls */
extern char **environ;
/* allows us to use built-ins commands */
int inbuilts(char *cmd);
/* a function that reverses a string */
void str_rvrs(char *strng, int ln);
/* a function that converts the string argument str to an integer (type int)*/
char *_itoa(int z);
/* a function that prints an error msg */
void errprt(char *nom, char *commd, int indx);
/* a function that frees an array */
void array_freed(char **ptrarr);
/* a function that executes a prompt */
int s_g_exec(char **cmd, char **av, int indx);
char *cmd_rd(void); /* a function that reads a command */
char **tknze(char *ln); /* a function that tokenize a string into small chunks */
char*sduplic(const char *strng); /* a function that duplicates a string */
char *scopy(char *destin, char *source);/* a function that copies a string */
char *sconcat(char *destin, char *source);/* a function that concatenates a string */
int slength(char *t);/* a function that lengthens a string */
int scomp(char *str1, char *str2);/* a function that compares two strings */
int plus_num(char *strng);/* a function that change negative num to positive */
int _atoi(char *strng);/* a function that converts the string argument str to an integer (type int)*/
char *_envrnget(char *varnm);/* a function that gets envrnments*/
char *_pget(char *commd);/* a function that gets PATH*/
void builtn_hdl(char **cmd, char **av , int *sttus, int indx);/* a function that handles built-ins*/
void environ_prt(char **cmd, int *sttus);/*a function that prints envrmnts*/
void exit_func(char **cmd, char **av, int *sttus, int indx);/* a function that that exit the shell */



#endif /* S_G_SHELL */
