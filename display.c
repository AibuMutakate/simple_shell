#include "shell.h"

/**
 * display - display the user for input
 * @option: check the option
 * Return: none
 */
void display(int option)
{
	char *buffer = NULL;

	if (option == 1)
		write(1, "My shell : ", 11);

	buffer = _getinput();

	if (option == 1)
		split(buffer, 1);
	else
		split(buffer, 2);
}
