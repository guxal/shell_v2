#include "header.h"

/**
 * main - create shell
 * @argc: arguments number
 * @argv: array call arg unused
 * Return: Success or Fail
 */

int main(int argc, char *argv[])
{
	char *buf = NULL;
	args_t args;
	int status;

	if (argc != 1)
	{
		printf("Usage: hsh\n");
		exit(1);
	}
	if (handle_sigaction() == -1)
	{
		printf("Failure installing sighandler\n");
		return (1);
	}
	node = build_node();
	node->namep = malloc(sizeof(char) * _strlen(argv[0]) + 1);
	node->namep = _strcpy(node->namep, argv[0]);
	while (EOF)
	{
		/* print prompt */
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 5);
		node->cexe++;
		buf = read_line();
		if (buf == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}
		else
		{
			args = split_line(buf);
			execute(args.argv, node->path);
			delete_memory(args.argv, args.argc);
			free(buf);
		}
	} status = node->status;
	free_node();
	return (status);
}
