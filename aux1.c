#include "main.h"

/**
 * ay1 - a
 * Return: b
 */
void ay1(void)
{
	char *help = "env: env [option] [name=value] [command [arg_list]]\n\t";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, custom_len(help));
}
/**
 * ay2 - a
 * Return: void
 */
void ay2(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, custom_len(help));
}
/**
 * ay3 - a
 * Return: void
 */
void ay3(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, custom_len(help));
}

/**
 * ay4 - a
 * Return: void
 */
void ay4(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, custom_len(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "[arg_list]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, custom_len(help));
}
/**
 * ay5 - a
 * Return: void
 */
void ay5(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, custom_len(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, custom_len(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, custom_len(help));
}
