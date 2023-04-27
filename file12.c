#include "main.h"

/**
 * exchange_char - a
 * @y: b
 * @bool: c
 * Return: d
 */
char *exchange_char(char *y, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; y[i]; i++)
		{
			if (y[i] == '|')
			{
				if (y[i + 1] != '|')
					y[i] = 16;
				else
					i++;
			}

			if (y[i] == '&')
			{
				if (y[i + 1] != '&')
					y[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; y[i]; i++)
		{
			y[i] = (y[i] == 16 ? '|' : y[i]);
			y[i] = (y[i] == 12 ? '&' : y[i]);
		}
	}
	return (y);
}

/**
 * node_join_new - a
 * @h_s: b
 * @h_l: c
 * @input: d
 * Return: void
 */
void node_join_new(div_all_list **h_s, list_of_all_lines **h_l, char *input)
{
	int i;
	char *line;

	input = exchange_char(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			join_node_at_end(h_s, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			join_node_at_end(h_s, input[i]);
			i++;
		}
	}

	line = custom_tok(input, ";|&");
	do {
		line = exchange_char(line, 1);
		add_line_node_end(h_l, line);
		line = custom_tok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * n_m_t_n - go to the next command line storednxt
 * @l_s: dvd
 * @l_l: cmd
 * @abcd: ds
 * Return: void
 */
void n_m_t_n(div_all_list **l_s, list_of_all_lines **l_l, my_struct *abcd)
{
	int loop_sep;
	div_all_list *ls_s;
	list_of_all_lines *ls_l;

	loop_sep = 1;
	ls_s = *l_s;
	ls_l = *l_l;

	while (ls_s != NULL && loop_sep)
	{
		if (abcd->status == 0)
		{
			if (ls_s->divider == '&' || ls_s->divider == ';')
				loop_sep = 0;
			if (ls_s->divider == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->divider == '|' || ls_s->divider == ';')
				loop_sep = 0;
			if (ls_s->divider == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*l_s = ls_s;
	*l_l = ls_l;
}

/**
 * div_inputed_cmd - bv
 * @abcd: ds
 * @input: i
 * Return: int
 */
int div_inputed_cmd(my_struct *abcd, char *input)
{

	div_all_list *h_s, *l_s;
	list_of_all_lines *h_l, *l_l;
	int loop;

	h_s = NULL;
	h_l = NULL;

	node_join_new(&h_s, &h_l, input);

	l_s = h_s;
	l_l = h_l;

	while (l_l != NULL)
	{
		abcd->input = l_l->line;
		abcd->arg_list = tokenize_a_line(abcd->input);
		loop = custom_execveee(abcd);
		free(abcd->arg_list);

		if (loop == 0)
			break;

		n_m_t_n(&l_s, &l_l, abcd);

		if (l_l != NULL)
			l_l = l_l->next;
	}

	call_free_on_list(&h_s);
	call_free_on_all_lines(&h_l);

	if (loop == 0)
		return (0);
	return (1);
}
