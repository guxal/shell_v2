#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/**
 * struct path_s - singly linked list of the path
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node struct
 * for create path in linked list
 */
typedef struct path_s
{
	char *str;
	unsigned int len;
	struct path_s *next;
} path_t;

/**
 * struct env_s - singly linked list of the env
 * @key: string - (malloc'ed string)
 * @value: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node struct
 * for create env in linked list
 */
typedef struct env_s
{
	char *key;
	char *value;
	struct env_s *next;
} env_t;

/**
 * struct args - arguments
 * @argc: numbers of argv
 * @argv: double pointer of strings
 *
 * Description: struct arguments
 */
typedef struct args
{
	int argc;
	char **argv;
} args_t;

/**
 * struct node_s - containt node path and length nodes
 * @env: singly linked list of env
 * @path: singly linked list of path
 * @len: length of nodes in singly linked list paths
 * @namep: name of the program
 * @cexe: counter executions
 * @status: status program exit
 *
 * Description: node path and length nodes
 */
typedef struct node_s
{
	env_t *env;
	path_t *path;
	size_t len;
	char *namep;
	int cexe;
	int status;
} node_t;

/**
 * struct built_f - Struct built in
 * @fc: name function
 * @f: &address function call
 */
typedef struct built_f
{
	char *fc;
	int (*f)(char **argv);
} built_t;

/*--- Global ---*/
extern node_t *node;
node_t *node;

/*--- Environ ---*/
extern char **environ;

int built_cd(char **args);
int built_help(char **args);
int built_exit(char **args);
int built_env(char **args);
/* void _buildenv(env_t *env); */

int (*get_built_func(char *s))(char **);

int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int execute(char **argv, path_t *path);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/* char *_getenv(const char *name); */
env_t *_getenv(const char *name, env_t *env);
int _setenv(env_t *env, char *name, char *value);
char *read_line(void);

void free_list_p(path_t *head);
void delete_memory(char **table, int value);
void *_calloc(unsigned int nmemb, unsigned int size);

args_t split_line(char *buf);

path_t *add_node(path_t **head, char *str);
path_t *create_node_p(char *data, char *separator);
size_t node_len_p(const path_t *h);

env_t *create_node_e(void);
void free_list_e(env_t *head);

node_t *build_node(void);

int handle_sigaction(void);

#endif
