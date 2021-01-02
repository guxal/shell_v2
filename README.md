# Shell V2

#cisfun$ is a simple shell implementation of the Bash Shell in the C Programming language. that can be compiled and runned from the command line. It contains the most basic features and functions found in the various shell programs.

## Usage

You must include in your function the "header.h" header:

```bash
#include "header.h"
```

The directory contents should be compiled with the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Then you can run our mini_shell function like this:

```bash
.hsh
```
And you will get this prompt:

```bash
#cisfun$
```

## Files and functions
- File: Authors

- File: man_1_simple_shell

o

- _File: _calloc.c

   void *_calloc(unsigned int nmemb, unsigned int size);

   o _calloc

- File: delete_memory.c

  void delete_memory(char **table, int value);

  o delete_memory

- File: execute.c

  int execute(char **argv);

  o execute

- File: header.h

  o header

- File: main.c

  o main

- File: read_line.c

  char *read_line(void);

  o read_line

- File: split_line.c

  args_t split_line(char *buf);

  o split_line

- File: strcmp.c

 int _strcmp(char *s1, char *s2);

  o strcmp

- File: strcpy.c

char *_strcpy(char *dest, char *src)

  o strcpy

- File: strlen.c

char *_strcpy(char *dest, char *src)

  o strlen

## Autors

Jonathan Cardenas Pabon email: 892@holbertonschool.com github: https://github.com/guxal

Rolando Quiroz email: 906@holbertonschool.com github: https://github.com/rolandoquiroz



## License
[MIT](https://choosealicense.com/licenses/mit/)# SIMPLE SHELL
