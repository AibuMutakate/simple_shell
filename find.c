#include "shell.h"
void free_all_buffer(char *backup, char **env_cpy, char *path);

/**
 * locate - locate path and execute the command
 * @arg_array: array of inputted characters
 * @backup: backup of buffer
 * @option: keep track of option for interractive and non interractive
 * Return: void
 */
void locate(char **arg_array, char *backup, int option)
{
	int i = 0;
	char *token = NULL, *key = "PATH", *path = NULL, *msg = ": not found\n", *g;
	char **env_cpy;
	struct stat st;

	if (custom_cmp(arg_array[0], "exit") == 0)
	{
		if (arg_array[1])
			exit(custom_atoi(arg_array[1]));
		exit(0);
	}
	while (environ[i])
		i++;
	env_cpy = malloc(sizeof(char *) * i);
	for (i = 0; environ[i]; i++)
		env_cpy[i] = custom_dup(environ[i]);
	env_cpy[i] = NULL;
	i = 0;
	while (env_cpy[i])
	{
		token = strtok(env_cpy[i++], "=");
		if (custom_cmp(key, token) == 0)
			break;
	}
	token = strtok(NULL, "\0");
	token = strtok(token, ":");
	while (token)
	{
		path = malloc(sizeof(char) * (custom_len(token) + custom_len(backup) + 1));
		custom_cat(path, token), custom_cat(path, "/"), custom_cat(path, backup);
		if (stat(path, &st) == 0)
		{
			arg_array[0] = custom_dup(path);
			execute(arg_array, backup, option);
		}
		token = strtok(NULL, ":");
	}
	g = custom_cat(arg_array[0], msg);
	write(1, g, custom_len(g));
	free_all_buffer(backup, env_cpy, path);
}

/**
 * free_all_buffer - free all malloc
 * @backup: copy of buffer
 * @env_cpy: copy of enviroment variable
 * @path: path to command
 * Return: void
 */
void free_all_buffer(char *backup, char **env_cpy, char *path)
{
	free(backup);
	free(env_cpy);
	free(path);
	display(1);
}
