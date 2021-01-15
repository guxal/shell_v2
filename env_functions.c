#include "header.h"
/**
 * *_getenv - get enviroment with match name from linkelist
 * @name: name of match
 * @env: linked list with env
 * Return: enviroment
 */
env_t *_getenv(const char *name, env_t *env)
{
	env_t *tmp;

	tmp = env;
	/* printf("key - %s\n", name); */
	while (tmp)
	{
		if (_strcmp(tmp->key, (char *) name) == 0)
		{
			/* printf("tmp value - %s\n", tmp->value); */
			return (tmp);
		}
		tmp = tmp->next;
	}

	return (NULL);
}
/**
 * *_memset - fills memory with a constant byte
 * @s: array memory
 * @b: constant byte
 * @n: memory length
 * Return: array *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		s[n] = b;
	return (s);
}

/**
 * _setenv - setter environt value by name
 * @env: enviroment linked list
 * @name: name of the environt
 * @value: new value
 * Return: Success 1, Error 0
 */
int _setenv(env_t **env, char *name, char *value)
{
	env_t *tmp = _getenv(name, *env);
	int len = _strlen(value) + 1;
	
	if (tmp == NULL)
	{
		/* printf("here\n"); */
		add_node_e(env, name, value);
		return (1);
	}
	/* printf("value %s\n", tmp->value); */
	free(tmp->value);
	tmp->value = malloc(sizeof(char *) * len);
	tmp->value = _memset(tmp->value, 0, len);

	if (tmp->value == NULL)
	 	return (0);

	tmp->value = _strcpy(tmp->value, value);
	return (1);
}
