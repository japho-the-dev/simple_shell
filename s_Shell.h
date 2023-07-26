#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

/* Prototypes*/
int main(int argc, char *argv[], char **env);
void display_prompt(void);
void print_number(int n);
void custom_error(char *cmd);
void execute_command(char **env, char *command_line, char *delimiter);
char *_strcat(char *dest, char *src);
char *path(char *cmd);
int _strcmp(char *s1, char *s2);

#endif
