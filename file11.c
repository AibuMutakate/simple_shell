#include "main.h"



/**
 * check_in_vars - a
 * @h: b
 * @in: c
 * @st: d
 * @data: e
 * Return: f
 */
int check_in_vars(len_of_var **h, char *in, char *st, my_struct *data)
{
	int i, lst, lpd;

	lst = custom_len(st);
	lpd = custom_len(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				var_join_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				var_join_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				var_join_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				var_join_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				var_join_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				var_join_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				var_join_node(h, 0, NULL, 0);
			else
				check_in_en(h, in + i, data);
		}
	}

	return (i);
}

/**
 * sub_input_with_another - a
 * @hd: b
 * @input: c
 * @n_i: d
 * @nlen: e
 * Return: str
 */
char *sub_input_with_another(len_of_var **hd, char *input, char *n_i, int nlen)
{
	len_of_var *indx;
	int i, j, k;

	indx = *hd;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				n_i[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					n_i[i] = indx->val[k];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			n_i[i] = input[j];
			j++;
		}
	}

	return (n_i);
}

/**
 * sub_value - a
 * @input: b
 * @abcd: c
 * Return: d
 */
char *sub_value(char *input, my_struct *abcd)
{
	len_of_var *hd, *indx;
	char *status, *n_i;
	int olen, nlen;

	status = func_a_to_i(abcd->status);
	hd = NULL;

	olen = check_in_vars(&hd, input, status, abcd);

	if (hd == NULL)
	{
		free(status);
		return (input);
	}

	indx = hd;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	n_i = malloc(sizeof(char) * (nlen + 1));
	n_i[nlen] = '\0';

	n_i = sub_input_with_another(&hd, input, n_i, nlen);

	free(input);
	free(status);
	release_all_rvar_list(&hd);

	return (n_i);
}
