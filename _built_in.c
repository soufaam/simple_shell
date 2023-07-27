#include "main.h"

/**
 * builtin_command - execute built-in function
 * @tmp: line without \\n;
 * @ln: 3 param
 * @tab: 4 param
 * @fg: 5 param the flage parameter
 * @pth: the path variable
 * @st: the status
 * Return: Always 0
 **/
void builtin_command(char *ln, char *tmp, char **pth, char **tab, int *fg, int st)
{
	int var = 0;

	if (_strncmp(tab[0], "exit", 4) == 0)
	{
		*fg = 1;
		free_grid(tab);
		free(tmp);
		free(ln);
		free_path(pth);
		exit(0);
	}
	if (_strncmp(tab[0], "env", 3) == 0)
	{
		*fg = 1;
		print_env();
	}
	else
		*fg = 0;
	st = errno;
	var = var + st +  errno;
}
