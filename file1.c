#include "main.h"

/**
 * carrier - a
 * @lpt: b
 * @buffer: c
 * @n: n
 * @j: j
 */
void carrier(char **lpt, size_t *n, char *buffer, size_t j)
{

	if (*lpt == NULL)
	{
		if (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lpt = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lpt = buffer;
	}
	else
	{
		custom_cpy(*lpt, buffer);
		free(buffer);
	}
}

/**
 * custom_helper_func - a
 * @abcd: b
 * Return: Return 0
 */
int custom_helper_func(my_struct *abcd)
{

	if (abcd->arg_list[1] == 0)
		ay4();
	else if (custom_cmp(abcd->arg_list[1], "setenv") == 0)
		ay2();
	else if (custom_cmp(abcd->arg_list[1], "env") == 0)
		ay1();
	else if (custom_cmp(abcd->arg_list[1], "unsetenv") == 0)
		ay3();
	else if (custom_cmp(abcd->arg_list[1], "help") == 0)
		ay6();
	else if (custom_cmp(abcd->arg_list[1], "exit") == 0)
		ay5();
	else if (custom_cmp(abcd->arg_list[1], "cd") == 0)
		ay8();
	else if (custom_cmp(abcd->arg_list[1], "alias") == 0)
		ay7();
	else
		write(STDERR_FILENO, abcd->arg_list[0],
			  custom_len(abcd->arg_list[0]));

	abcd->status = 0;
	return (1);
}

/**
 * abc11 - a
 * @dre: b
 */
void abc11(int dre)
{
	(void)dre;
	write(STDOUT_FILENO, "\nMy Shell: ", 11);
}

/**
 * func_get_builtin - a
 * @cmd: b
 * Return: c
 * struct: des
 * struct_for_buit: ok
 */
int (*func_get_builtin(char *cmd))(my_struct *)
{
	struct_for_buit builtin[] = {
		{"env", custom_enviroment},
		{"exit", func_quit},
		{"setenv", custome_set_env},
		{"unsetenv", custome_unset_env},
		{"cd", cmd_cchange_shell},
		{"help", custom_helper_func},
		{NULL, NULL}};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (custom_cmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}
