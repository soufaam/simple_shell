#include "main.h"

/**
 * builtin_command - execute built-in function
 * @line: 3 param
 * @tab: 4 param
 * @flag: 5 param
 * @path: the path variable
 * Return: Always 0
 **/
void builtin_command(char *line, char **path, char **tab, int *flag)
{
	if (_strncmp(tab[0], "exit", 4) == 0)
	{
		*flag = 1;
		free_grid(tab);
		free(line);
		free_path(path);
		exit(0);
	}
	if (_strncmp(tab[0], "env", 3) == 0)
	{
		*flag = 1;
		print_env();
	}
	else
		*flag = 0;
}
