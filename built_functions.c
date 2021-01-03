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
	/* printf("home : %s\n", home->value); */
	/* printf("old home : %s\n", oldh->value); */
	if (args[1] == NULL)
	{
		if (home->value)
			chdir(home->value);
		/* fprintf(stderr, "lsh: expected argument to \"cd\"\n"); */
	}
	else if (*args[1] == '-')
	{
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
	}
	nwd = getcwd(nwd, 0);
	/* set environt */
	_setenv(node->env, "OLDPWD", cwd);
	_setenv(node->env, "PWD", nwd);
	/* set environt */
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
int built_exit(__attribute__((unused)) char **args)
{
	_exit(node->status);
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
