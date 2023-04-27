#include "main.h"

/**
 * custom_execveee - a
 * @abcd: b
 * Return: c
 */
int custom_execveee(my_struct *abcd)
{
	int (*builtin)(my_struct *abcd);

	if (abcd->arg_list[0] == NULL)
		return (1);

	builtin = func_get_builtin(abcd->arg_list[0]);

	if (builtin != NULL)
		return (builtin(abcd));

	return (custom_exe(abcd));
}

/**
 * cmd_cd_future - a
 * @abcd: b
 * Return: void
 */
void cmd_cd_future(my_struct *abcd)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = abcd->arg_list[1];
	if (chdir(dir) == -1)
	{
		abc10(abcd, 2);
		return;
	}

	cp_pwd = custom_dup(pwd);
	setcustom_enviroment("OLDPWD", cp_pwd, abcd);

	cp_dir = custom_dup(dir);
	setcustom_enviroment("PWD", cp_dir, abcd);
	free(cp_pwd);
	free(cp_dir);
	abcd->status = 0;
	chdir(dir);
}

/**
 * check_in_en - a
 * @h: b
 * @in: c
 * @data: d
 * Return: void
 */
void check_in_en(len_of_var **h, char *in, my_struct *data)
{
	int row, chr, j, lval;
	char **pq;

	pq = data->cus_env;
	for (row = 0; pq[row]; row++)
	{
		for (j = 1, chr = 0; pq[row][chr]; chr++)
		{
			if (pq[row][chr] == '=')
			{
				lval = custom_len(pq[row] + chr + 1);
				var_join_node(h, j, pq[row] + chr + 1, lval);
				return;
			}
			if (in[j] == pq[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	var_join_node(h, j, NULL, 0);
}
