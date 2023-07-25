#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* _strncpy -  Entrypoint
* Description: 'the program's description _strcpy
* @dest : 1 param
* @src : 2 param
* @n : param
*  Return: Always 0 (Success)
*/

char *_strncpy(char *dest, char *src, int n)
{
	int t = 0;

	if (n > 0)
		dest = malloc(n + 1);
	if (!dest)
		return (NULL);
	if (src)
		while ((*(src + t) != '\0') && t < n)
		{
			*(dest + t) = *(src + t);
			t++;
		}
	while (t <= n)
	{
		*(dest + t) = '\0';
		t++;
	}
	return (dest);
}
