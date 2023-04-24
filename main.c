#include "shell.h"

/**
 * main - entry point of the program
 * Return: int
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 0)
	{
		display(2);
	}

	display(1);
	return (0);
}
