#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
char *_getinput();
char *custom_copy(char *dest, char *src);
int custom_len(char *s);
void display(int);
void split(char *buffer, int);
void execute(char **, char *, int);
void locate(char **, char *, int);
int custom_atoi(char *s);
char *custom_cat(char *dest, char *src);
int custom_cmp(char *a, char *b);
char *custom_dup(char *src);
char *custom_token(char *string, char b, int pos);


#endif
