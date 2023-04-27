#include "main.h"

/**
 * shell_loop_2 - a
 * @abcd: b
 *
 * Return: void
 */
void shell_loop_2(my_struct *abcd)
{
	int loop, r;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "My Shell: ", 10);
		input = line_reading_cmd(&r);
		if (r != -1)
		{
			input = shell_loop_2_1(input);
			if (input == NULL)
				continue;

			if (custom_perror_0(abcd, input) == 1)
			{
				abcd->status = 2;
				free(input);
				continue;
			}
			input = sub_value(input, abcd);
			loop = div_inputed_cmd(abcd, input);
			abcd->keep_count += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

/**
 * shell_loop_2_1 - a
 *
 * @in: b
 * Return: c
 */
char *shell_loop_2_1(char *in)
{
	int i, q;

	q = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				q = i;
		}
	}
	if (q != 0)
	{
		in = custom_reallocate(in, i, q + 1);
		in[q] = '\0';
	}
	return (in);
}

/**
 * line_reading_cmd - a
 *
 * @b: b
 * Return: c
 */
char *line_reading_cmd(int *b)
{
	char *input = NULL;
	size_t bufsize = 0;

	*b = getline(&input, &bufsize, stdin);

	return (input);
}


/**
 * tokenize_a_line - divide line
 * @input: a
 * Return: b
 */
char **tokenize_a_line(char *input)
{
	size_t d;
	size_t i;
	char **tokens;
	char *token;

	d = buf_size_for_tok;
	tokens = malloc(sizeof(char *) * (d));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = custom_tok(input, delim_for_tok);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == d)
		{
			d += buf_size_for_tok;
			tokens = cus_re_dp(tokens, i, sizeof(char *) * d);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = custom_tok(NULL, delim_for_tok);
		tokens[i] = token;
	}

	return (tokens);
}

