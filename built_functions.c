#include "header.h"
/**
 * built_cd - change directory.
 * @args: arguments
 * Return: Always returns 1, to continue executing.
 */
int built_cd(char **args)
{
	char *nwd = NULL, *cwd = NULL, *tmp = NULL;

	env_t *home = _getenv("HOME", node->env);
	env_t *oldh = _getenv("OLDPWD", node->env);

	cwd = getcwd(cwd, 0);
	if (oldh == NULL)
	{
		_setenv(&node->env, "OLDPWD", cwd);
		oldh = _getenv("OLDPWD", node->env);
	}
	if (args[1] == NULL)
	{
		if (home != NULL)
			if (home->value)
				chdir(home->value);
		/* fprintf(stderr, "lsh: expected argument to \"cd\"\n"); */
	}
	else if (*args[1] == '-')
	{
		if (oldh != NULL)
			if (oldh->value)
				chdir(oldh->value);
		tmp = getcwd(tmp, 0);
		printf("%s\n", tmp);
		free(tmp);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			/* perror("hsh"); */
			print_error(args[1], 2);
		}
	} nwd = getcwd(nwd, 0);
	_setenv(&node->env, "OLDPWD", cwd);
	_setenv(&node->env, "PWD", nwd);
	free(nwd);
	free(cwd);
	return (1);
}
/**
 * built_help - print help.
 * @args: arguments.
 * Return: Always returns 1, to continue executing.
 */
int built_help(__attribute__((unused)) char **args)
{
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	printf("Use the man command for information on other programs.\n");
	return (1);
}
/**
 * built_exit - exit.
 * @args:  arguments.
 * Return: Always returns 0, to terminate execution.
 */
int built_exit(char **args)
{
	if (args[1] == NULL)
		_exit(node->status);
	else if (args[1][0] >= '0' && args[1][0] <= '9')
		_exit(_atoi(args[1]));
	else
		print_error(args[1], 3);
	node->status = 2;
	return (0);
}
/**
 * built_env - print environ
 * @args: arguments
 * Return: Always returns 1, to continue executing.
 */
int built_env(__attribute__((unused)) char **args)
{
	env_t *env = node->env;

	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (1);
}
