#include "main.h"

/**
 * getline_error -  getline_erro function that exit
 * @_st: first parameter
 * @line: second parameter
 * @tab: third parameter
 * Return: Always void
 **/
void getline_error(char *_st, char *line, char **tab)
{
	free_memory(_st, line, tab);
	exit(1);
}
/**
 * free_memory - free memory
 * @_st: first parameter
 * @line: second parameter
 * @tab: third parameter
 * Return: Always void
 **/

void free_memory(char *_st, char *line, char **tab)
{
	free(_st);
	free(line);
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
