#include "main.h"




/**
 *sig_handler -  SIGINT handler
 *@signo: first param
 * Return: Always 0
 **/
void sig_handler(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
	fflush(stdout);
}
/**
 * main - Entry point
 *@ac: first paramter
 *@av: second parameter
 * Return: Always 0
 **/

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	size_t buffer_size = 0, i = 0;
	int numberchar, status = 0, flag = 0;
	char *line = NULL, **tab = NULL, *cmd = NULL, *tmp = NULL, **path = NULL;

	signal(SIGINT, sig_handler);
	while (1)
	{
		path = strtow(_getenv("PATH"), ':');
		shell_prompt(&buffer_size, &i);
		numberchar = getline(&line, &buffer_size, stdin);
		if (get_line_tester(line, &tmp, &numberchar, path) == 1)
			continue;
		tab = strtow(tmp, ' ');
		if (tab)
		{
			builtin_command(line, tmp, path, tab, &flag, status);
			if (flag)
			{
				free_memory(tmp, cmd, line, tab);
				continue;
			}
			cmd = _find_command(tab[0], path);
			child(&status, &flag, cmd, line, tab, path);
			if (!flag)
				write_not_found_error(av[0], i, cmd);
		}
		free_memory(tmp, cmd, line, path);
	}
	return (0);
}
