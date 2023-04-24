#include "shell.h"

/**
 * custom_dup - duplicate a string
 * @src: string to duplicate
 * Return: pointer to the duplicated sting
 */
char *custom_dup(char *src)
{

	char *dest;
	int i;
	int len = custom_len(src);

	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
	{
		perror("Can't malloc space");
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
