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
#define DELIM "\t\r\n\a"
#define MAX_LINE 80



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
int main(void);
int hsh_exit(char **args);
int hsh_env(char **args);
int is_builtin(char *command);
int execute_command(char **args);
char **parse_line(char *line);
void handle_signal(int signal);

#endif
