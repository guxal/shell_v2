#include "header.h"
/**
 * delete_memory - delete memory in double pointer
 * @table: double pointer
 * @value: size free
 */
void delete_memory(char **table, int value)
{
	int i;

	for (i = 0; i < value; i++)
		free(table[i]);
	free(table);
}
