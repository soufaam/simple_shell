#include "main.h"

/**
 * _setenv - set env variable
 * @variable: ..
 * @value: ..
 * @overwrite: 1 or 0
 * Return: -1 if fail 0 on success
 */

int _setenv(const char *variable, const char *value, int overwrite)
{
	extern char **environ;
	char *val;
	int i;

	if (variable == NULL || variable[0] == '\0')
	{
		perror("setenv error: invalid variable name");
		return (-1);
	}

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp((const char *)environ[i], variable, (size_t)_strlen((char *)variable)) == 0)
		{
			if (overwrite != 0)
			{
				val = malloc(_strlen((char *)variable) + _strlen((char *)value) + 2);

				if (val == NULL)
					return (-1);
				
				_strcpy((char *)val, (char *)variable);
				_strcat((char *)val, "=");
				_strcat((char *)val, (char *)value);
				environ[i] = val;
			}
			return (0);
		}
	}
	val = malloc(_strlen((char *)variable) + _strlen((char *)value) + 2);

	_strcpy((char *)val, (char *)variable);
	_strcat((char *)val, "=");
	_strcat((char *)val, (char *)value);
	environ[i] = val;
	i++;
	environ[i] = NULL;
	return (0);
}
/**
 * _strc - function
 * @str: string
 * @ch: character
 * Return: true or false
 */
int _strc(const char *str, char ch)
{
	while (*str != '\0' && *str != ch)
		str++;
	return (*str == ch);

}
/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	size_t len = _strlen(src), i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
