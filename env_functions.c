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
	while (tmp)
	{
		if (_strcmp(tmp->key, (char *) name) == 0)
			return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * _setenv - setter environt value by name
 * @env: enviroment linked list
 * @name: name of the environt
 * @value: new value
 * Return: Success 1, Error 0
 */
int _setenv(env_t *env, char *name, char *value)
{
	env_t *tmp;

	tmp = _getenv(name, env);
	free(tmp->value);
	tmp->value = malloc(sizeof(char *) * _strlen(value));

	if (tmp->value == NULL)
		return (0);

	tmp->value = _strcpy(tmp->value, value);
	return (1);
}
