#include "main.h"

/**
 * builtin_command - execute built-in function
 * @command: 1 param
 * Return: Always 0
 **/
void builtin_command(char *command)
{
	if (_strcmp(command, _strdup("exit")) == 0)
	{
		exit(1);
	}
	if (_strcmp(command, _strdup("env")) == 0)
	{
		print_env();
	}
}
