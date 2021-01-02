#include "header.h"
/**
 * get_built_func - return built function
 * @s: char
 * Return: function (char **)
 */
int (*get_built_func(char *s))(char **)
{
	built_t fs[] = {
		{"cd", built_cd},
		{"env", built_env},
		{"help", built_help},
		{"exit", built_exit},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (i < 4)
	{
		if (_strcmp(fs[i].fc, s) == 0)
			return (fs[i].f);
		i++;
	}
	return (NULL);
}
