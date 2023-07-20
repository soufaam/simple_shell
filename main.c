#include "main.h"




/**
 *sig_handler -  SIGINT handler
 *@signo: first param
 * Return: Always 0
 **/
void sig_handler(int signo)
{
	exit(signo);
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
	int numerchar, status;
	__pid_t pid;
	char *line = NULL, **tab = NULL, *_st = NULL;

	signal(SIGINT, sig_handler);
	while (1)
	{
		write(STDOUT_FILENO, "$ ", _strlen("$ "));
		numerchar = getline(&line, &buffer_size, stdin);
		i++;
		if (numerchar == -1)
			getline_error(_st, line, tab);
		tab = strtow(line, ' ');
		if (tab[1])
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", av[0]);
			continue;
		}
		builtin_command(tab[0]);
		if (_stat(tab[0]) == 0)
		{
			pid = fork();
			if (pid == -1)
				getline_error(_st, line, tab);
			if (pid == 0)
			{
				if (execve(tab[0],  tab, environ) == -1)
					dprintf(STDERR_FILENO, "%s: %lu: %s: not found\n", av[0], i, _st);
			}
			else
				wait(&status);
		}
		else
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", av[0]);
	}
	free_memory(_st, line, tab);
	return (0);
}
