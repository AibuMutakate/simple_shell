
#include "shell.h"
void delete_after_hash(char *buff);
/**
 * _getinput - custome getline to read input from user
 * Return: pointer to input address
 */
char *_getinput()
{
	int i, buffsize = 1024, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
	}
	buff[i] = '\0';
	delete_after_hash(buff);
	return (buff);
}

/**
 * delete_after_hash - remove everything after #
 * @buff: input read from buffer;
 * Return:void
 */
void delete_after_hash(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
