#include "main.h"

/**
 * err_chech_rep - a
 * @input: b
 * @i: i
 * Return: int
 */
int err_chech_rep(char *input, int i)
{
	if (*(input - 1) == *input)
		return (err_chech_rep(input - 1, i + 1));

	return (i);
}

/**
 * err_separate_ops - f
 *
 * @input: i
 * @i: i
 * @last: l
 * Return: int
 */
int err_separate_ops(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (err_separate_ops(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = err_chech_rep(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = err_chech_rep(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_separate_ops(input + 1, i + 1, *input));
}

/**
 * find_first_character - a
 *
 * @input: i
 * @i: i
 * Return: int
 */
int find_first_character(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * custom_perror_1 - a
 *
 * @abcd: b
 * @input: c
 * @i: d
 * @bool: e
 * Return: f
 */
void custom_perror_1(my_struct *abcd, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *keep_count;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	keep_count = func_a_to_i(abcd->keep_count);
	length = custom_len(abcd->av[0]) + custom_len(keep_count);
	length += custom_len(msg) + custom_len(msg2) + custom_len(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(keep_count);
		return;
	}
	custom_cpy(error, abcd->av[0]);
	custom_cat(error, ": ");
	custom_cat(error, keep_count);
	custom_cat(error, msg2);
	custom_cat(error, msg);
	custom_cat(error, msg3);
	custom_cat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(keep_count);
}

/**
 * custom_perror_0 - a
 * @abcd: d
 * @input: b
 * Return: int
 */
int custom_perror_0(my_struct *abcd, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = find_first_character(input, &begin);
	if (f_char == -1)
	{
		custom_perror_1(abcd, input, begin, 0);
		return (1);
	}

	i = err_separate_ops(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		custom_perror_1(abcd, input, begin + i, 1);
		return (1);
	}

	return (0);
}
