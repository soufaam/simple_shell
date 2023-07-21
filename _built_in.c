#include "main.h"

/**
 * builtin_command - execute built-in function
 * @cmd: 1 param
 * @_st: 2 param
 * @line: 3 param
 * @tab: 4 param
 * @flag: 5 param
 * Return: Always 0
 **/
void builtin_command(char *cmd, char *_st, char *line, char **tab, int *flag)
{
	if (_strcmp(cmd, _strdup("exit")) == 0)
	{
		*flag = 1;
		free_memory(_st, line, tab);
		exit(1);
	}
	if (_strcmp(cmd, _strdup("env")) == 0)
	{
		*flag = 1;
		print_env();
	}
	else
		*flag = 0;
}
