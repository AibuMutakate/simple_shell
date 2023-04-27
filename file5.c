#include "main.h"

/**
 * abc4 - a
 * @abcd: b
 *
 * Return: c
 */
char *abc4(my_struct *abcd)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = func_a_to_i(abcd->keep_count);
	length = custom_len(abcd->av[0]) + custom_len(ver_str);
	length += custom_len(abcd->arg_list[0]) + custom_len(abcd->arg_list[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	custom_cpy(error, abcd->av[0]);
	custom_cat(error, ": ");
	custom_cat(error, ver_str);
	custom_cat(error, ": ");
	custom_cat(error, abcd->arg_list[0]);
	custom_cat(error, ": Illegal number: ");
	custom_cat(error, abcd->arg_list[1]);
	custom_cat(error, "\n\0");
	free(ver_str);

	return (error);
}

/**
 * join_node_at_end - a
 * @head: b
 * @sep: c
 * Return: ptr
 */
div_all_list *join_node_at_end(div_all_list **head, char sep)
{
	div_all_list *new, *temp;

	new = malloc(sizeof(div_all_list));
	if (new == NULL)
		return (NULL);

	new->divider = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * ay6 - a.
 * Return: void
 */
void ay6(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, custom_len(help));
}
