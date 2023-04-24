#include "shell.h"

/**
 *custom_copy - copies the string pointed to by src
 *@dest: A pointer to a char that will be changed
 *@src: A pointer to a char that will be changed
 *Return: dest
 */

char *custom_copy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * custom_len - func to check length of string
 * Description: print length of strings
 * @b: character to check its length
 * Return: length of the string
 */
int custom_len(char *b)
{
	int i = 0;

	while (b[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * custom_atoi - convert string to curr int value
 * @s: string to convert
 * Return: converted int value
 */
int custom_atoi(char *s)
{
	int i, sign = 1, flag = 0, final;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		final = -result;
	else
		final = result;
	return (final);
}

/**
 * custom_cat - concatenate two strings
 * @dest: destination to concatenate to
 * @src: source to concatenate from
 * Return: pointer to destination
 */

char *custom_cat(char *dest, char *src)
{
	char *point = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (point);
}

/**
 * custom_cmp - compare two strings
 * @a: first string to compare
 * @b: second string to compare
 * Return: 0 if same, 1 if not same
 */

int custom_cmp(char *a, char *b)
{
	int i;

	if (custom_len(a) != custom_len(b))
	{
		return (1);
	}
	for (i = 0; a[i]; i++)
	{
		if (a[i] != b[i])
		{
			return (1);
		}
	}
	return (0);
}
