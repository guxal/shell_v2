# Make file for shell v2 project at Holberton school
# List variables
# SHELL = /bin/bash
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra -pedantic
# NAME = hsh
#
# # Main directive
# all: $(NAME)
#
# # Compile executable from object files
# $(NAME): $(OBJ) $(HEADERS)
# 	$(CC) -o $@ $^ $(CFLAGS)

all:
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh