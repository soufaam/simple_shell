#include "main.h"



/**
 * free_all - free memory
 * @tmp: 1
 * @_st: 2 parameter
 * @path: 3 parameter
 * @tab: 4 parameter
 * Return: Always void
 **/

void free_all(char *tmp, char *_st, char **tab, char **path)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (_st)
	{
		free(_st);
		_st = NULL;
	}
	if (tab)
		free_grid(tab);
	free_path(path);
}
/**
 * builtin_command - execute built-in function
 * @tmp: line without \\n;
 * @ln: 3 param
 * @tab: 4 param
 * @fg: 5 param the flage parameter
 * @pth: the path variable
 * @av: agrument vector
 * @st: the status
 * @i: iteration
 * Return: Always 0
 **/
void builtin_command(char *ln, char *tmp, char **pth,
char **tab, char **av, int *fg, int *st, int i)
{
	int exit_stat = 0;
	char *str_stat = NULL;

	*fg = 1;
	if (_strncmp(tab[0], "exit", 4) == 0)
	{
		if (tab[1])
		{
			exit_stat = _atoi(tab[1]);
			str_stat = _strdup(tab[1]);
			if (exit_stat)
			{
				free_all(tmp, ln, tab, pth);
				exit(exit_stat);
			}
			else
			{
				write_illegal_error(av[0], str_stat, i);
				*st = 2;
				*fg = 2;
			}
		}
		else
		{
			free_all(tmp, ln, tab, pth);
			exit(*st);
		}
	}
	else if (_strncmp(tab[0], "env", 3) == 0)
	{
		*fg = 1;
		print_env();
	}
	else
		*fg = 0;
}
