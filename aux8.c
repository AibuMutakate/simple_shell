#include "main.h"

/**
 * check_is_cmd - a
 * @path: t
 * @i: b
 * Return: int
 */
int check_is_cmd(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * check_which - l
 * @cmd: c
 * @cus_env: b
 * Return: char
 */
char *check_which(char *cmd, char **cus_env)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = custom_getcustom_enviroment_var("PATH", cus_env);
	if (path)
	{
		ptr_path = custom_dup(path);
		len_cmd = custom_len(cmd);
		token_path = custom_tok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (check_is_cmd(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = custom_len(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			custom_cpy(dir, token_path);
			custom_cat(dir, "/");
			custom_cat(dir, cmd);
			custom_cat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = custom_tok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * check_execute - a
 *
 * @abcd: b
 * Return: void
 */
int check_execute(my_struct *abcd)
{
	struct stat st;
	int i;
	char *input;

	input = abcd->arg_list[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	abc10(abcd, 127);
	return (-1);
}

/**
 * check_cmd_error - a
 *
 * @dir: b
 * @abcd: c
 * Return: int
 */
int check_cmd_error(char *dir, my_struct *abcd)
{
	if (dir == NULL)
	{
		abc10(abcd, 127);
		return (1);
	}

	if (custom_cmp(abcd->arg_list[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			abc10(abcd, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(abcd->arg_list[0], X_OK) == -1)
		{
			abc10(abcd, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * custom_exe - a
 *
 * @abcd: b
 * Return: int
 */
int custom_exe(my_struct *abcd)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void)wpd;

	exec = check_execute(abcd);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = check_which(abcd->arg_list[0], abcd->cus_env);
		if (check_cmd_error(dir, abcd) == 1)
			return (1);
	}
	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = check_which(abcd->arg_list[0], abcd->cus_env);
		else
			dir = abcd->arg_list[0];
		execve(dir + exec, abcd->arg_list, abcd->cus_env);
	}
	else if (pd < 0)
	{
		perror(abcd->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	abcd->status = state / 256;
	return (1);
}
