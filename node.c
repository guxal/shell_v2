#include "header.h"
/**
 * build_node - build node with length nodes
 * Return: struct node (path, len)
 */
node_t *build_node(void)
{
	path_t *head;
	/* node_t n; */
	env_t *env;
	env_t *get_env;
	char *delim = ":";

	env = NULL;
	env = create_node_e();

	node = malloc(sizeof(node_t));
	if (node == NULL)
		return (NULL);
	/* printf("env: %s\n", env->key); */

	get_env = _getenv("PATH", env);
	node->path = NULL;
	if (get_env != NULL)
	{
		head = create_node_p(get_env->value, delim);
		node->len = node_len_p(head);
		/* printf("path : %s\n", get_env->value); */
		node->path = head;
	}
	node->env = env;
	node->cexe = 0;
	node->status = 0;
	/* node = &n; */
	return (node);
}

/**
 * free_node - free node
 */
void free_node(void)
{
	if (node->path != NULL)
		free_list_p(node->path);
	free_list_e(node->env);
	free(node->namep);
	free(node);
}
