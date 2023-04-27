#include "main.h"

/**
 * abc6 - a
 * @abcd: d
 * Return: err
 */
char *abc6(my_struct *abcd)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = func_a_to_i(abcd->keep_count);
	msg = ": Unable to add/remove from environment\n";
	length = custom_len(abcd->av[0]) + custom_len(ver_str);
	length += custom_len(abcd->arg_list[0]) + custom_len(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	custom_cpy(error, abcd->av[0]);
	custom_cat(error, ": ");
	custom_cat(error, ver_str);
	custom_cat(error, ": ");
	custom_cat(error, abcd->arg_list[0]);
	custom_cat(error, msg);
	custom_cat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * abc9 - er
 * @abcd: d
 *
 * Return: err
 */
char *abc9(my_struct *abcd)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = func_a_to_i(abcd->keep_count);
	length = custom_len(abcd->av[0]) + custom_len(ver_str);
	length += custom_len(abcd->arg_list[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	custom_cpy(error, abcd->av[0]);
	custom_cat(error, ": ");
	custom_cat(error, ver_str);
	custom_cat(error, ": ");
	custom_cat(error, abcd->arg_list[0]);
	custom_cat(error, ": Permission denied\n");
	custom_cat(error, "\0");
	free(ver_str);
	return (error);
}
