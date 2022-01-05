#ifndef CSANSOM_MYSHELL_C
#define CSANSOM_MYSHELL_C

#include "myshell.h"

extern char **getln();

int main() {

    char **args;
    int background = 0;

    while(1) {
        if (background);
            signal(SIGCHLD, SIG_IGN);
        printf("myshell$ ");
        args = getln();
        if (args[0]) {
            int argc = 0;
            while (args[argc+1]) {
                argc++;
            }
            if (!strcmp(args[0], "exit") && argc == 0) {
                printf("myshell has been terminated\n");
                exit(0);
            } else if (!strcmp(args[0], "add")) {
                int sum = 0;
                for (int i = 0; i < argc; i++) {
                    int temp = strtol(args[i+1], NULL, (args[i+1][1] == 'x' || args[i+1][1] == 'X')? 16: 10);
                    sum += temp;
                    printf("%s", args[i+1]);
                    printf((!args[i+2])? " = ": " + ");
                }
                printf("%d\n", sum);
            } else if (!strcmp(args[0], "args")) {
                printf("argc = %d, args = ", argc);
                for (int i = 1; i < argc + 1; i++) {
                    printf("%s", args[i]);
                    if (i < argc)
                        printf(", ");
                }
                printf("\n");
            } else if (!strcmp(args[0], "reverse")) {
                for (int i = 1; i < argc + 1; i++) {
                    char * reversed = reverse(args[i]);
                    printf("reverse(%s) = %s", args[i], reversed);
                    if (i < argc)
                        printf(", ");
                    free(reversed);
                }
                printf("\n");
            } else {
                if (background)
                    signal(SIGCHLD, signalHandler);
                int pid = fork();
                background = (!strcmp(args[argc], "&") && argc > 0)? 1: 0;
                if (pid == 0) {
                    if (argc > 1) {
                        if (!strcmp(args[argc-1], ">")) {
                            freopen(args[argc], "w", stdout);
                            args[argc-1] = args[argc] = NULL;
                        } else if (!strcmp(args[argc-1], "<")) {
                            freopen(args[argc], "r", stdin);
                            args[argc-1] = args[argc] = NULL;
                        }
                    }
                    if (background) {
                        args[argc] = NULL;
                        if (argc > 2) {
                            if (!strcmp(args[argc-2], ">")) {
                                freopen(args[argc-1], "w", stdout);
                                args[argc-2] = args[argc-1] = NULL;
                            }
                            else if (!strcmp(args[argc-2], "<")) {
                                freopen(args[argc-1], "r", stdin);
                                args[argc-2] = args[argc-1] = NULL;
                            }
                        }
                    }
                    execvp(args[0], args);
                    perror("Execution Error");
                    exit(0);
                } else if (pid > 0) {
                   if (background)
                       printf("pid=%d\n", pid);
                   else
                       wait(NULL);
                } else {
                    perror("Forking Error");
                    exit(1);
                }
            }
        }
    }
    return 0;
}

void signalHandler(int sig) {
    printf("\nBackground process running\n");
}

char * reverse(char *str) {
    int length = strlen(str);
    char * reversed = malloc(sizeof(char) * (length+1));
    for (int i = length; i > 0; i--) {
        reversed[length-i] = str[i-1];
    }
    reversed[length] = '\0';
    return reversed;
}

#endif
