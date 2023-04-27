#include "main.h"

/**
 * cmd_cd_present - c
 * @abcd: d
 * Return: void
 */
void cmd_cd_present(my_struct *abcd)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cpcustom_tok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = custom_dup(pwd);
	setcustom_enviroment("OLDPWD", cp_pwd, abcd);
	dir = abcd->arg_list[1];
	if (custom_cmp(".", dir) == 0)
	{
		setcustom_enviroment("PWD", cp_pwd, abcd);
		free(cp_pwd);
		return;
	}
	if (custom_cmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cpcustom_tok_pwd = cp_pwd;
	custom_string_rev(cpcustom_tok_pwd);
	cpcustom_tok_pwd = custom_tok(cpcustom_tok_pwd, "/");
	if (cpcustom_tok_pwd != NULL)
	{
		cpcustom_tok_pwd = custom_tok(NULL, "\0");

		if (cpcustom_tok_pwd != NULL)
			custom_string_rev(cpcustom_tok_pwd);
	}
	if (cpcustom_tok_pwd != NULL)
	{
		chdir(cpcustom_tok_pwd);
		setcustom_enviroment("PWD", cpcustom_tok_pwd, abcd);
	}
	else
	{
		chdir("/");
		setcustom_enviroment("PWD", "/", abcd);
	}
	abcd->status = 0;
	free(cp_pwd);
}

/**
 * cd_previous - a
 * @abcd: d
 * Return: void
 */
void cd_previous(my_struct *abcd)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_owd, *cp_pwd, *cp_owd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = custom_dup(pwd);

	p_owd = custom_getcustom_enviroment_var("OLDPWD", abcd->cus_env);

	if (p_owd == NULL)
		cp_owd = cp_pwd;
	else
		cp_owd = custom_dup(p_owd);

	setcustom_enviroment("OLDPWD", cp_pwd, abcd);

	if (chdir(cp_owd) == -1)
		setcustom_enviroment("PWD", cp_pwd, abcd);
	else
		setcustom_enviroment("PWD", cp_owd, abcd);

	p_pwd = custom_getcustom_enviroment_var("PWD", abcd->cus_env);

	write(STDOUT_FILENO, p_pwd, custom_len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_owd)
		free(cp_owd);

	abcd->status = 0;

	chdir(p_pwd);
}

/**
 * cmd_cd_future_home - c
 * @abcd: a
 * Return: void
 */
void cmd_cd_future_home(my_struct *abcd)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = custom_dup(pwd);

	home = custom_getcustom_enviroment_var("HOME", abcd->cus_env);

	if (home == NULL)
	{
		setcustom_enviroment("OLDPWD", p_pwd, abcd);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		abc10(abcd, 2);
		free(p_pwd);
		return;
	}

	setcustom_enviroment("OLDPWD", p_pwd, abcd);
	setcustom_enviroment("PWD", home, abcd);
	free(p_pwd);
	abcd->status = 0;
}

/**
 * cmd_cchange_shell - a
 * @abcd: d
 * Return: int
 */
int cmd_cchange_shell(my_struct *abcd)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = abcd->arg_list[1];

	if (dir != NULL)
	{
		ishome = custom_cmp("$HOME", dir);
		ishome2 = custom_cmp("~", dir);
		isddash = custom_cmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cmd_cd_future_home(abcd);
		return (1);
	}

	if (custom_cmp("-", dir) == 0)
	{
		cd_previous(abcd);
		return (1);
	}

	if (custom_cmp(".", dir) == 0 || custom_cmp("..", dir) == 0)
	{
		cmd_cd_present(abcd);
		return (1);
	}

	cmd_cd_future(abcd);

	return (1);
}
