#include "main.h"

/**
 * custom_mem_cpy - a
 * @newptr: ptr
 * @ptr: ptr
 * @size: size
 *
 * Return: void
 */
void custom_mem_cpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * custom_reallocate - a
 * @ptr: ptr
 * @old_s: s
 * @ns: a
 * Return: ptr.
 */
void *custom_reallocate(void *ptr, unsigned int old_s, unsigned int ns)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(ns));

	if (ns == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ns == old_s)
		return (ptr);

	newptr = malloc(ns);
	if (newptr == NULL)
		return (NULL);

	if (ns < old_s)
		custom_mem_cpy(newptr, ptr, ns);
	else
		custom_mem_cpy(newptr, ptr, old_s);

	free(ptr);
	return (newptr);
}

/**
 * cus_re_dp - a
 * @ptr: d
 * @old_s: x
 * @ns: n
 * Return: ptr.
 */
char **cus_re_dp(char **ptr, unsigned int old_s, unsigned int ns)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * ns));

	if (ns == old_s)
		return (ptr);

	newptr = malloc(sizeof(char *) * ns);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_s; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
