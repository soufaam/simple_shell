#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _strcat -  Entrypoint
* Description: 'the program's description _strcat
* @dest : 1 param
* @src : 2 param
*  Return: Always 0 (Success)
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, len;

	len = _strlen(dest);
	if (dest[len - 1] != '/')
	{
		dest[len] = '/';
		dest[len + 1] = '\0';
		len++;
	}
	while (*(src + i) != '\0')
	{
		*(dest + (len + i)) = *(src + i);
		i++;
	}
	*(dest + (len + i)) = '\0';
	return (dest);
}
