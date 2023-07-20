#include <stdlib.h>
#include <time.h>
#include "main.h"


/**
* _strcmp -  string comparaison
* Description: 'the program's description _strcmp
* @s1 : 1 param
* @s2 : 2 param
*  Return: Always 0 (Success)
*/

int _strcmp(char *s1, char *s2)
{
	int result, i = 0;

	result = *(s1 + i) - *(s2 + i);
	while (*(s1 + i) != '\0' && (*(s1 + i) - *(s2 + i)) == 0)
	{
		i++;
		result = *(s1 + i) - *(s2 + i);
	}
	return (result);
}
