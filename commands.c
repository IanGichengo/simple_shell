#include "shell.h"

/* Execute a command */
int execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    if (args == NULL || args[0] == NULL)
        return (1);
    

    if (is_builtin(args[0])) {
        return hsh_exit(args) || hsh_env(args);
    }

    pid = fork();

    if (pid == 0) {
        /* Child process */
        if (execve(args[0], args, environ) == -1) {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Fork error */
        perror("hsh");
    } else {
        /* Parent process */
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}
