#include "main.h"

/**
 * getline_error -  getline_erro function that exit
 * @_st: first parameter
 * @line: second parameter
 * @tab: third parameter
 * @path: 4 parameter
 * Return: Always void
 **/
void getline_error(char *_st, char *line, char **tab, char **path)
{
	(void) _st, (void) line, (void)tab;
	free_memory(NULL, _st, line, tab);
	free_path(path);
	path = NULL;
	exit(1);
}
/**
 * free_memory - free memory
 * @tmp: 1
 * @_st: 2 parameter
 * @line: 3 parameter
 * @tab: 4 parameter
 * Return: Always void
 **/

void free_memory(char *tmp, char *_st, char *line, char **tab)
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
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (tab)
		free_grid(tab);
}

/**
 * write_error - write error
 * @filename: second parameter
 * Return: Always void
 **/
void write_error(char *filename)
{
	write(STDERR_FILENO, filename, _strlen(filename));
	write(STDERR_FILENO, ": No such file or directory\n",
	 _strlen(": No such file or directory\n"));
}
