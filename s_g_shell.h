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

extern char **environ;

int inbuilts(char *cmd);

void str_rvrs(char *strng, int ln);

char *_itoa(int z);

void errprt(char *nom, char *commd, int indx);

void array_freed(char **ptrarr);

int s_g_exec(char **cmd, char **av, int indx);
char *cmd_rd(void);
char **tknze(char *ln);
char*sduplic(const char *strng);
char *scopy(char *destin, char *source);
char *sconcat(char *destin, char *source);
int slength(char *t);
int scomp(char *str1, char *str2);
int plus_num(char *strng);
int _atoi(char *strng);
char *_envrnget(char *varnm);
char *_pget(char *commd);
void builtn_hdl(char **cmd, char **av , int *sttus, int indx);
void environ_prt(char **cmd, int *sttus);
void exit_func(char **cmd, char **av, int *sttus, int indx);



#endif
