#include "main.h"


/**
 * get_line - a
 * @lineptr: b
 * @n: c
 * @stream: d
 * Return: e
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buf;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buf = custom_reallocate(buf, input, input + 1);
		buf[input] = t;
		input++;
	}
	buf[input] = '\0';
	bring_line(lineptr, n, buf, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

/**
 * free_data - free
 * @abcd: ds
 * Return: void
 */
void free_data(my_struct *abcd)
{
	unsigned int i;

	for (i = 0; abcd->cus_env[i]; i++)
	{
		free(abcd->cus_env[i]);
	}

	free(abcd->cus_env);
	free(abcd->pid);
}

/**
 * set_data - Int
 * @abcd: ds
 * @av: arg
 * Return: void
 */
void set_data(my_struct *abcd, char **av)
{
	unsigned int i;

	abcd->av = av;
	abcd->input = NULL;
	abcd->arg_list = NULL;
	abcd->status = 0;
	abcd->keep_count = 1;

	for (i = 0; environ[i]; i++)
		;

	abcd->cus_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		abcd->cus_env[i] = custom_dup(environ[i]);
	}

	abcd->cus_env[i] = NULL;
	abcd->pid = func_a_to_i(getpid());
}

/**
 * main - main point
 *
 * @agc: argc
 * @argv: argv
 *
 * Return: 0 on success.
 */
int main(int agc, char **argv)
{
	my_struct abcd;
	(void)agc;

	signal(SIGINT, abc11);
	set_data(&abcd, argv);
	shell_loop_2(&abcd);
	free_data(&abcd);
	if (abcd.status < 0)
		return (255);
	return (abcd.status);
}
