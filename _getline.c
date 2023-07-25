#include "main.h"



/**
* findchar - ENTRYPOINT
* @s: string
* @c: char
* @len: lenght
* Return: 0 success or uint
*/

int findchar(char *s, char c, int *len)
{
	int i, find = 0, lenght = 0;

	lenght = _strlen(s);
	for (i = 0; i < lenght; i++)
		if (*(s + i) == c)
		{
			find = 1;
			*len = i + 1;
			break;
		}
	return (find);
}
/**
* _strcat_interne -  Entrypoint
* Description: 'the program's description _strcat
* @dest: 1 param
* @src: 2 param
* Return: Always 0 (Success)
*/

char *_strcat_interne(char *dest, char *src)
{
	int i = 0, len_dest, len_src;
	char *tmpstr = NULL, *destr = NULL;

	tmpstr = _strdup(dest);
	len_dest = _strlen(tmpstr);
	len_src = _strlen(src);
	destr = malloc(len_dest + len_src + 1);
	if (tmpstr)
		while (*(tmpstr + i) != '\0')
		{
			*(destr + i) = *(tmpstr + i);
			i++;
		}
	i = 0;
	if (src)
		while (*(src + i) != '\0')
		{
			*(destr + (len_dest + i)) = *(src + i);
			i++;
		}
	*(destr + (len_dest + len_src)) = '\0';
	free(tmpstr);
	return (destr);
}


/**
 * free_str - write error
 * @str: second parameter
 * @tmp: buffer size
 * @tmp_str: file descriptor
 * Return: Always void
 **/


void free_str(char *str, char *tmp, char *tmp_str)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	if (tmp_str)
		free(tmp_str);
}
/**
 * _getline - write error
 * @line: second parameter
 * @buffer_size: buffer size
 * @fd: file descriptor
 * Return: Always void
 **/

size_t _getline(char **line, size_t *buffer_size, size_t fd)
{
	size_t tmp_buffer_size = 80, numberchar = 0;
	int len = -1;
	char *str = NULL, *tmp_str = NULL, *tmp = NULL;

	str = malloc(tmp_buffer_size * sizeof(char) + 1);
	numberchar = read(fd, str, tmp_buffer_size);
	if (findchar(str, '\n', &len))
	{
		tmp = _strncpy(tmp, str, len);
		tmp_str = _strcat_interne(tmp_str, tmp);
		*line = _strdup(tmp_str);
		free_str(str, tmp, tmp_str);
		return (_strlen(*line));
	}
	if (numberchar == 1)
	{
		*buffer_size = numberchar;
		*line = str;
		free(str);
		return (*buffer_size);
	}
	*buffer_size = numberchar;
	while (numberchar > 0)
	{
		str[numberchar] = '\0';
		if (findchar(str, '\n', &len))
		{
			tmp = _strncpy(tmp, str, len);
			tmp_str = _strcat_interne(tmp_str, tmp);
			break;
		}
		tmp_str = _strcat_interne(tmp_str, str);
		numberchar = read(fd, str, tmp_buffer_size);
		*buffer_size += numberchar;
	}
	*line = _strdup(tmp_str);
	free_str(str, tmp, tmp_str);
	if (numberchar <= 0)
		return (-1);
	return (*buffer_size);
}

/**void main(void)
{
	char *line = NULL;
	size_t buffer_size = 0, numberchar;

	write(STDOUT_FILENO, "$ ", 2);
	numberchar = _getline(&line, &buffer_size, STDIN_FILENO);
	printf("%d \n", (int)numberchar);
	write(STDOUT_FILENO, line, _strlen(line));
	write(STDOUT_FILENO, "$ ", 3);
	numberchar = getline(&line, &buffer_size, stdin);
	printf("%d \n", (int)numberchar);
	write(STDOUT_FILENO, line, _strlen(line));
}
*/