#include "main.h"



/**
 * ay8 - a.
 * Return: void
 */
void ay8(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, custom_len(help));
}


/**
 * abc1 - a
 *
 * @abcd: b
 * @msg: c
 * @error: d
 * @ver_str: e
 * Return: err
 */
char *abc1(my_struct *abcd, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	custom_cpy(error, abcd->av[0]);
	custom_cat(error, ": ");
	custom_cat(error, ver_str);
	custom_cat(error, ": ");
	custom_cat(error, abcd->arg_list[0]);
	custom_cat(error, msg);
	if (abcd->arg_list[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = abcd->arg_list[1][1];
		illegal_flag[2] = '\0';
		custom_cat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		custom_cat(error, abcd->arg_list[1]);
	}

	custom_cat(error, "\n");
	custom_cat(error, "\0");
	return (error);
}

/**
 * call_free_on_list - a
 * @head: b
 * Return: c
 */
void call_free_on_list(div_all_list **head)
{
	div_all_list *cty;
	div_all_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((cty = curr) != NULL)
		{
			curr = curr->next;
			free(cty);
		}
		*head = NULL;
	}
}

/**
 * abc3 - a
 * @abcd: d
 * Return: err
 */
char *abc3(my_struct *abcd)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = func_a_to_i(abcd->keep_count);
	length = custom_len(abcd->av[0]) + custom_len(ver_str);
	length += custom_len(abcd->arg_list[0]) + 16;
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
	custom_cat(error, ": not found\n");
	custom_cat(error, "\0");
	free(ver_str);
	return (error);
}
