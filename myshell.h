#ifndef CSANSOM_MYSHELL_H
#define CSANSOM_MYSHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void signalHandler();
char *reverse();

#endif
