#include "main.h"


/**
 * _find_command -  SIGINT handler
 * @command: 1 param
 * Return: Always 0
 **/

char *_find_command(char *command)
{
	int i = 0;
	char **path = NULL;
	char *var_str = NULL, *result_cat = NULL;
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	var_str = _getenv("PATH");
	path = strtow(var_str, ':');
	if (path)
		for (i = 0; path[i] != NULL; i++)
		{
			result_cat = _strcat(path[i], command);
			if (stat(result_cat, &st) == 0)
			{
				return (result_cat);
			}
		}
	return (command);
}
