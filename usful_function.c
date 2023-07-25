#include "main.h"


/**
 * shell_prompt -  shell_prompt function that handles shell prompt
 * @i: the number of lines
 * @buffer_size: the buffer size
 * Return: Always void
 **/
void shell_prompt(size_t *buffer_size, size_t *i)
{
	*buffer_size = 0;
	*i = 1 + *i;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", _strlen("$ "));
}

/**
 * get_line_tester -  get_line_tester function that exit
 * @line: size_t inisialised with
 * @tmp: char pointer
 * @numberchar: the number of char
 * @path: the path variable
 * Return: Always void
 **/
int get_line_tester(char *line, char **tmp, int *numberchar, char **path)
{
	*tmp = _strncpy(*tmp, line, _strlen(line) - 1);
	if (*numberchar == -1)
	{
		free_path(path);
		free(line);
		exit(0);
	}
	if (*numberchar == 1)
	{
		free(line);
		return (1);
	}
	return (*numberchar);
}
