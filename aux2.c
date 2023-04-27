#include "main.h"

/**
 * var_join_node - a
 * @head: b
 * @lvar: c
 * @val: d
 * @lval: le
 * Return: len
 */
len_of_var *var_join_node(len_of_var **head, int lvar, char *val, int lval)
{
	len_of_var *new, *temp;

	new = malloc(sizeof(len_of_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * release_all_rvar_list - f
 * @head: a
 * Return: void
 */
void release_all_rvar_list(len_of_var **head)
{
	len_of_var *temp;
	len_of_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * custom_string_rev - a
 * @s: i
 * Return: n
 */
void custom_string_rev(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
