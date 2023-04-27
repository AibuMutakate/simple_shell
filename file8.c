#include "main.h"

/**
 * abc10 - a
 * @abcd: b
 * @eval: c
 * Return: d
 */

int abc10(my_struct *abcd, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = abc6(abcd);
		break;
	case 126:
		error = abc9(abcd);
		break;
	case 127:
		error = abc3(abcd);
		break;
	case 2:
		if (custom_cmp("exit", abcd->arg_list[0]) == 0)
			error = abc4(abcd);
		else if (custom_cmp("cd", abcd->arg_list[0]) == 0)
			error = abc2(abcd);
		break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, custom_len(error));
		free(error);
	}
	abcd->status = eval;
	return (eval);
}
