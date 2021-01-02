#include "header.h"

/**
 * _strlen - string length
 * @str: string
 * Return: integer length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		++i;
	return (i);
}
