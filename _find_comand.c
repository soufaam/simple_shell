#include "main.h"


/**
 * _find_command -  SIGINT handler
 * @command: 1 param
 * @path: 2 parameter
 * Return: Always 0
 **/

char *_find_command(char *command, char **path)
{
	int i = 0;
	char *result_cat = NULL;

	if (access(command, X_OK) == 0)
		return (_strdup(command));
	for (i = 0; path[i] != NULL; i++)
	{
		result_cat = _strcat(path[i], command);
		if (access(result_cat, X_OK) == 0)
			return (result_cat);
		free(result_cat);
		result_cat = NULL;
	}
	return (_strdup(command));
}
