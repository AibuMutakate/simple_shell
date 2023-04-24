#include "shell.h"

/**
 * split - tokenize the buffer read from user
 * @buffer: input from user
 * @option: use to track option if interractive or not
 * Return: void
 */
void split(char *buffer, int option)
{
	char *backup = NULL, *token = NULL;
	char **arg_array = NULL;
	struct stat st;
	int argc = 0, i = 0;

	backup = malloc(sizeof(char) * custom_len(buffer));
	if (backup == NULL)
	{
		free(buffer);
		exit(0);
	}
	custom_copy(backup, buffer);
	token = strtok(buffer, " \n");

	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}
	arg_array = malloc(sizeof(char *) * argc);
	if (arg_array == NULL)
	{
		free(buffer);
		exit(0);
	}
	token = strtok(backup, " \n");
	while (token)
	{
		arg_array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	arg_array[i] = NULL;
	free(buffer);
	if (arg_array[0][0] == '/' && stat(backup, &st) == 0)
	{
		execute(arg_array, backup, option);
	}

	locate(arg_array, backup, option);
}
