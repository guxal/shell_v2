#include "header.h"
/**
 * *_strcat - concatene two strings
 * @dest: destinity
 * @src: source
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int str_length_dest = _strlen(dest);
	int str_length_src = _strlen(src);
	int str_length_max = str_length_dest + str_length_src - 1;
	int i;
	int count = 0;

	for (i = str_length_dest; i <= str_length_max; i++)
	{
		dest[i] = src[count];
		count++;
	}
	dest[i] = '\0';

	return (dest);
}
