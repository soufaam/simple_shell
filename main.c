#include "main.h"




/**
 *sig_handler -  SIGINT handler
 *@signo: first param
 * Return: Always 0
 **/
void sig_handler(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
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
	int numerchar, status, flag = 0;
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
		if (numerchar == 1)
			continue;
		tab = strtow(line, ' ');
		if (tab[1])
		{
			write_error(av[0]);
			continue;
		}
		builtin_command(tab[0], _st, line, tab, &flag);
		if (_stat(tab[0]) == 0)
		{
			pid = fork();
			if (pid == -1)
				getline_error(_st, line, tab);
			if (pid == 0)
				execute(tab[0], tab, av[0], i, _st);
			else
				wait(&status);
		}
		else if (!flag)
			write_error(av[0]);
	}
	free_memory(_st, line, tab);
	return (0);
}
