#include "header.h"
/**
 * launch - launch commands
 * @argv: arguments
 * Return: Success or Fail
 */
int launch(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else if (pid < 0)
	{
		perror("#cisfun$ ");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		/* wait(NULL); */
	}

	return (1);
}
/**
 * execute - execute
 * @argv: double pointer
 * @path: PATH array
 * Return: none
 */
int execute(char **argv, path_t *path)
{
	int (*built)(char **);
	/* int i; */
	char *concat;
	struct stat st;

	if (argv[0] == NULL)
		return (1);
	if (argv[0][0] == '/' || argv[0][0] == '.')
		return (launch(argv));

	built = get_built_func(argv[0]);

	if (built != NULL)
		return (built(argv));

	while (path)
	{
		concat = malloc((_strlen(path->str) + 1) * sizeof(char));
		_strcpy(concat, path->str);
		/* debe cambiar */
		concat = realloc(concat,
				sizeof(char) * ((_strlen(path->str) + _strlen(argv[0]) + 1)));
		concat = _strcat(concat, argv[0]);
		if (stat(concat, &st) == 0)
		{
			free(argv[0]);
			argv[0] = malloc((_strlen(concat) + 1) * sizeof(char));
			argv[0] = _strcpy(argv[0], concat);
			free(concat);
			return (launch(argv));
		}
		else
			free(concat);
		path = path->next;
	}

	return (1);
}
