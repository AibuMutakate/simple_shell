#include "main.h"

/**
 * info_cpy - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *info_cpy(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = custom_len(name);
	len_value = custom_len(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	custom_cpy(new, name);
	custom_cat(new, "=");
	custom_cat(new, value);
	custom_cat(new, "\0");

	return (new);
}

/**
 * setcustom_enviroment - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @abcd: data structure (environ)
 * Return: no return
 */
void setcustom_enviroment(char *name, char *value, my_struct *abcd)
{
	int i;
	char *varcustom_enviroment, *namecustom_enviroment;

	for (i = 0; abcd->cus_env[i]; i++)
	{
		varcustom_enviroment = custom_dup(abcd->cus_env[i]);
		namecustom_enviroment = custom_tok(varcustom_enviroment, "=");
		if (custom_cmp(namecustom_enviroment, name) == 0)
		{
			free(abcd->cus_env[i]);
			abcd->cus_env[i] = info_cpy(namecustom_enviroment, value);
			free(varcustom_enviroment);
			return;
		}
		free(varcustom_enviroment);
	}

	abcd->cus_env = cus_re_dp(abcd->cus_env, i, sizeof(char *) * (i + 2));
	abcd->cus_env[i] = info_cpy(name, value);
	abcd->cus_env[i + 1] = NULL;
}

/**
 * custome_set_env - compares env variables names
 * with the name passed.
 * @abcd: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int custome_set_env(my_struct *abcd)
{

	if (abcd->arg_list[1] == NULL || abcd->arg_list[2] == NULL)
	{
		abc10(abcd, -1);
		return (1);
	}

	setcustom_enviroment(abcd->arg_list[1], abcd->arg_list[2], abcd);

	return (1);
}

/**
 * custome_unset_env - deletes a environment variable
 *
 * @abcd: data relevant (env name)
 *
 * Return: 1 on success.
 */
int custome_unset_env(my_struct *abcd)
{
	char **realloccus_env;
	char *varcustom_enviroment, *namecustom_enviroment;
	int i, j, k;

	if (abcd->arg_list[1] == NULL)
	{
		abc10(abcd, -1);
		return (1);
	}
	k = -1;
	for (i = 0; abcd->cus_env[i]; i++)
	{
		varcustom_enviroment = custom_dup(abcd->cus_env[i]);
		namecustom_enviroment = custom_tok(varcustom_enviroment, "=");
		if (custom_cmp(namecustom_enviroment, abcd->arg_list[1]) == 0)
		{
			k = i;
		}
		free(varcustom_enviroment);
	}
	if (k == -1)
	{
		abc10(abcd, -1);
		return (1);
	}
	realloccus_env = malloc(sizeof(char *) * (i));
	for (i = j = 0; abcd->cus_env[i]; i++)
	{
		if (i != k)
		{
			realloccus_env[j] = abcd->cus_env[i];
			j++;
		}
	}
	realloccus_env[j] = NULL;
	free(abcd->cus_env[k]);
	free(abcd->cus_env);
	abcd->cus_env = realloccus_env;
	return (1);
}
