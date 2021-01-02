#include "header.h"
/**
 * *read_line - read line for stdin
 * Return: Success or Fail
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;

	fflush(stdin);
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
