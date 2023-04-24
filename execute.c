#include "shell.h"

/**
 * execute - function to execute the commands
 * @arg_array: list of tokenized array
 * @backup: backup of buffer that was tokenized
 * @option: to know the state if its interractive or non interractive
 * Return: void
 */
void execute(char **arg_array, char *backup, int option)
{
	if (fork() == 0)
	{
		if (execve(arg_array[0], arg_array, environ) == 1)
			perror("");
	}
	else
	{
		wait(NULL);
		free(backup);
		free(arg_array);
		if (option == 2)
			exit(1);
		display(1);
	}
}
