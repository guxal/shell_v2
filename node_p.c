#include "header.h"

/**
 * free_list_p - free list
 * @head: head node list
 */
void free_list_p(path_t *head)
{
	path_t *tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
	free(head);
}
/**
 * node_len_p - length list
 * @h: list path
 * Return: integer length
 */
size_t node_len_p(const path_t *h)
{
	size_t count = 0;

	while (h)
		h = h->next, count++;
	return (count);
}
/**
 * *add_node_p - add node in list
 * @head: head
 * @str: string
 * Return: List_t
 */
path_t *add_node_p(path_t **head, char *str)
{
	path_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(path_t));
	if (new == NULL)
		return (NULL);
	new->str = malloc((_strlen(str) + 2) * sizeof(char));
	if (new->str == NULL)
		return (NULL);
	new->str = _strcpy(new->str, str);
	new->str = _strcat(new->str, "/");
	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
/**
 * *create_node_p - create a node
 * @data: data from create
 * @separator: delimiter inside data
 * Return: new node
 */
path_t *create_node_p(char *data, char *separator)
{
	path_t *new;
	char *token;
	char *tmp;

	tmp = malloc((_strlen(data) + 1) * sizeof(char));
	tmp = _strcpy(tmp, data);

	new = NULL;
	token = strtok(tmp, separator);
	while (token)
		add_node_p(&new, token), token = strtok(NULL, separator);

	free(tmp);
	return (new);
}
