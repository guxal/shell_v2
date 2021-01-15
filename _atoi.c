#include "header.h"

/**
 * _atoi - convert int to string
 * @s: string
 * Return: int
 */
int _atoi(char *s)
{
	int str = _strlen(s);
	int i;
	int sign = 1;
	unsigned int sum = 0;

	for (i = 0; i <= str; i++)
	{
		if (s[i] == '-')
			sign = sign * -1;
		if (s[i] == '+')
			sign = sign * +1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			sum = (s[i] - 48)  + (sum * 10);
		}
		if (sum > 0 && s[i] == ' ')
			break;
	}

	if (sign < 0)
		sum = sum * -1;

	return (sum);
}
