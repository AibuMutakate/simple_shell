#include "main.h"

/**
 * custom_getcustom_enviroment_var - get an environment variable
 * @name: name of the environment variable
 * @cus_env: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *custom_getcustom_enviroment_var(const char *name, char **cus_env)
{
	char *ptrcustom_enviroment;
	int i, mov;

	/* Initialize ptrcustom_enviroment value */
	ptrcustom_enviroment = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; cus_env[i]; i++)
	{
		/* If name and env are equal */
		mov = cmpcustom_enviroment_name(cus_env[i], name);
		if (mov)
		{
			ptrcustom_enviroment = cus_env[i];
			break;
		}
	}

	return (ptrcustom_enviroment + mov);
}

/**
 * custom_enviroment - prints the evironment variables
 *
 * @abcd: data relevant.
 * Return: 1 on success.
 */
int custom_enviroment(my_struct *abcd)
{
	int i, j;

	for (i = 0; abcd->cus_env[i]; i++)
	{

		for (j = 0; abcd->cus_env[i][j]; j++)
			;

		write(STDOUT_FILENO, abcd->cus_env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	abcd->status = 0;

	return (1);
}
