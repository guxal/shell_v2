#include "header.h"

/**
 * print_error - print error shell
 * @verror: value error argv
 * @terror: type error
 */
void print_error(char *verror, int terror)
{
	const char error_arr[3][26] = {
		"not found",
		"No such file or directory",
		"can't cd to"
	};

	if (terror == 0)
		node->status = 127;
	else
		node->status = 1;

	if (terror != 2)
		fprintf(stderr, "%s: %d: %s: %s\n", node->namep,
			node->cexe, verror, error_arr[terror]);
	else
		fprintf(stderr, "%s: %d: cd: %s %s\n", node->namep,
			node->cexe, error_arr[terror], verror);

	fflush(stderr);
}
