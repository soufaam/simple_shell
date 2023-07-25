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
	int numberchar, status, flag = 0;
	__pid_t pid;
	char *line = NULL, **tab = NULL, *cmd = NULL, *tmp = NULL, **path = NULL;

	signal(SIGINT, sig_handler);
	path = strtow(_getenv("PATH"), ':');
	while (1)
	{
		shell_prompt(&buffer_size, &i);
		numberchar = _getline(&line, &buffer_size, STDIN_FILENO);
		if (get_line_tester(line, &tmp, &numberchar, path) == 1)
			continue;
		tab = strtow(tmp, ' ');
		if (tab)
		{
			builtin_command(tmp, path, tab, &flag);
			if (flag)
			{
				free_memory(tmp, cmd, line, tab);
				continue;
			}
			cmd = _find_command(tab[0], path);
			if (access(cmd, X_OK) == 0)
			{
				pid = fork();
				if (pid == -1)
					getline_error(cmd, line, tab, path);
				if (pid == 0)
					execute(cmd, tab);
				else
					wait(&status);
			}
			else if (!flag)
				write_not_found_error(av[0], i, cmd);
		}
		free_memory(tmp, cmd, line, tab);
	}
	return (0);
}
