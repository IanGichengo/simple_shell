#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* For Read/Write Buffers */
#define MAX_INPUT_LENGTH 1024
#define BUFFER_SIZE 1024



extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;



/* PROTOTYPES */
void display_prompt(void);
void execute_command(char **command);
ssize_t read_input(char *buffer, size_t size);
char *append_char(char *str, char c, size_t *size);
char *custom_getline(void);
void exit_shell(void);
char *find_next_token(char *str, char delimiter, char **save_ptr);
void print_environment(char **env_vars);




#endif
