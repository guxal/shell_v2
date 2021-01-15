#include "header.h"

/**
 * free_list_e - free list env
 * @head: head node list
 */
void free_list_e(env_t *head)
{
	env_t *tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(head);
}
/**
 * node_len_e - length list
 * @h: list path
 * Return: integer length
 */
size_t node_len_e(const env_t *h)
{
	size_t count = 0;

	while (h)
		h = h->next, count++;
	return (count);
}
/**
 * *add_node_e - add node in list
 * @head: head
 * @key: string
 * @value: string
 * Return: List_t
 */
env_t *add_node_e(env_t **head, char *key, char *value)
{
	env_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(env_t));
	if (new == NULL)
		return (NULL);
	new->key = malloc((_strlen(key) + 2) * sizeof(char));
	new->value = malloc((_strlen(value) + 2) * sizeof(char));
	if (new->key == NULL || new->value == NULL)
		return (NULL);
	new->key = _strcpy(new->key, key);
	new->value = _strcpy(new->value, value);
	new->next = *head;
	*head = new;
	return (new);

}
/**
 * *create_node_e - create a node enviroment
 * Return: new node
 */
env_t *create_node_e(void)
{
	char *delim = "=";
	char *token;
	char **ptr;
	env_t *new;
	int count = 0;
	char *tmp;

	new = NULL;
	ptr = environ;

	while (ptr[count])
	{
		/* printf("environ %s\n", ptr[count]); */
		token = strtok(ptr[count], delim);
		tmp = strtok(NULL, "");
		/* printf("value %s\n", tmp); */
		add_node_e(&new, token, tmp);
		count++;
	}
	return (new);
}
