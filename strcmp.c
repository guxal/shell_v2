#include "header.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: val
 */

int _strcmp(char *s1, char *s2)
{
	int count = 0;
	int val = 0;

	while (s1[count])
	{
		if (s1[count] != s2[count])
		{
			val = s1[count] - s2[count];
			break;
		}
		++count;
	}

	return (val);
}
