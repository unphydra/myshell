#ifndef __MYSHELL_H_
#define __MYSHELL_H_
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "colors.h"
#include "command.h"

void call_child(char** args);
char ** get_args(char * command);

#endif