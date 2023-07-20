#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

extern char **environ;
char *argstostr(int ac, char **av);
char *_getenv(const char *name);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **strtow(char *str, char delimeter);
char *_strcat(char *dest, char *src);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_strdup(char *str);
void free_grid(char **grid);
char *_find_command(char *command);
int _stat(char *command);
void getline_error(char *_st, char *line, char **tab);
void free_memory(char *_st, char *line, char **tab);
void print_env(void);
void builtin_command(char *command);

int _setenv(const char *variable, const char *value, int overwrite);
int _strchar(const char *str, char ch);
char *_strcpy(char *dest, char *src)
#endif
