#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* free_grid -  Entrypoint
* Description: 'the program's description free_grid
* @grid : 1 param
*  Return: Always 0 (Success)
*/
void free_grid(char **grid)
{
	int i;

	if (grid != NULL && grid[0] != NULL && grid[0][0] != '\0')
		for (i = 0; grid[i] != NULL; i++)
			free(grid[i]);
	free(grid);
}
