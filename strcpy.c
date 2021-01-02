#include "header.h"

/**
 * *_strcpy - copy string
 * @dest: destination
 * @src: source
 * Return: copy destination
 */

char *_strcpy(char *dest, char *src)
{
	int str = _strlen(src);
	int i;

	for (i = 0; i <= str; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
