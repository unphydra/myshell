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

typedef char * String ;
typedef String * String_ptr;

void call_child(String_ptr args);
String_ptr get_args(String command);

#endif