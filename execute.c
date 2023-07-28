#include "main.h"

/**
* prinInt - ENTRYPOINT
* @var: constant
* Return: 0 success or uint
*/
void  prinInt(int var)
{
	char ch;

	if (var < 0)
	{
		write(STDERR_FILENO, "-", 1);
		if (var == -2147483648)
		{
			var = -147483648;
			write(STDERR_FILENO, "2", 1);
		}
		var = -var;
	}
	if (var / 10)
		prinInt(var / 10);
	ch = var % 10 + '0';
	write(STDERR_FILENO, &ch, 1);
}

/**
* write_not_found_error -  auxilatry function
* Description: write_not_found_error read print error when occurs
* @av: 3 parameter
* @i: 4 parameter
* @cmd: 5 parameter
* @status: the exit status
* and return the the desired variable
* Return: Always 0 (Success)
**/

void write_not_found_error(char *av, int i, char *cmd, int *status)
{
	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	prinInt(i);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, " not found\n", _strlen(" not found\n"));
	*status = 127;
}

/**
* execute -  auxilatry function
* Description: _getenv read environment variables
* @command: 1 param
* @argv: 2 parameter
* and return the the desired variable
* Return: Always 0 (Success)
**/
void execute(char *command, char **argv)
{
	if (execve(command, argv, argv) == -1)
		perror("Failed to execute command\n");
}
