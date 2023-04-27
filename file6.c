#include "main.h"




/**
 * add_line_node_end - adds a command line at the end
 * of a list_of_all_lines.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
list_of_all_lines *add_line_node_end(list_of_all_lines **head, char *line)
{
	list_of_all_lines *new, *cty;

	new = malloc(sizeof(list_of_all_lines));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	cty = *head;

	if (cty == NULL)
	{
		*head = new;
	}
	else
	{
		while (cty->next != NULL)
			cty = cty->next;
		cty->next = new;
	}

	return (*head);
}

/**
 * call_free_on_all_lines - frees a list_of_all_lines
 * @head: head of the linked list.
 * Return: no return.
 */
void call_free_on_all_lines(list_of_all_lines **head)
{
	list_of_all_lines *cty;
	list_of_all_lines *curr;

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
 * ay7 - a
 * Return: void
 */
void ay7(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, custom_len(help));
}

/**
 * abc2 - a
 * @abcd: b
 * Return: c
 */
char *abc2(my_struct *abcd)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = func_a_to_i(abcd->keep_count);
	if (abcd->arg_list[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = custom_len(abcd->arg_list[1]);
	}

	length = custom_len(abcd->av[0]) + custom_len(abcd->arg_list[0]);
	length += custom_len(ver_str) + custom_len(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = abc1(abcd, msg, error, ver_str);

	free(ver_str);

	return (error);
}
