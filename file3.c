#include "main.h"

/**
 * bring_line - a
 * @lineptr: b
 * @buf: c
 * @n: d
 * @j: e
 */
void bring_line(char **lineptr, size_t *n, char *buf, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buf;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buf;
	}
	else
	{
		custom_cpy(*lineptr, buf);
		free(buf);
	}
}

/**
 * func_quit - a
 * @abcd: b
 * Return: int.
 */
int func_quit(my_struct *abcd)
{
	unsigned int a;
	int dig;
	int len;
	int num;

	if (abcd->arg_list[1] != NULL)
	{
		a = func_a_to_i_2(abcd->arg_list[1]);
		dig = check_digit(abcd->arg_list[1]);
		len = custom_len(abcd->arg_list[1]);
		num = a > (unsigned int)INT_MAX;
		if (!dig || len > 10 || num)
		{
			abc10(abcd, 2);
			abcd->status = 2;
			return (1);
		}
		abcd->status = (a % 256);
	}
	return (0);
}

/**
 * cmpcustom_enviroment_name - a
 * @t: b
 * @name: c
 * Return: 0
 */
int cmpcustom_enviroment_name(const char *t, const char *name)
{
	int i;

	for (i = 0; t[i] != '='; i++)
	{
		if (t[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}
