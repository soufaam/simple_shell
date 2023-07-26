#include "main.h"

/**
 * child - child
 * @status: 1
 * @cmd: the command
 * @ln: the string  line readed from getline
 * @tab: the 2 diemension table
 * @path: the environment variable that hold paths
 * @fg: flag indicates if the command is found or not
 * Return: Always void
 **/
void child(int *status, int *fg, char *cmd, char *ln, char **tab, char **path)
{

	if (access(cmd, X_OK) == 0)
	{
		__pid_t pid;

		*fg = 1;
		pid = fork();
		if (pid == -1)
			getline_error(cmd, ln, tab, path);
		if (pid == 0)
			execute(cmd, tab);
		else
			wait(status);
	}
	else
		*fg = 0;
}
