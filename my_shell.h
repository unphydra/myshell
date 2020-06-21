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
#include "typedef.h"
#include "file_parser.h"

void call_child(String_ptr args, Process_stream ps);
Dynamic_strings_ptr string_spliter(String, String);
void parse_ps_one(String line);

#endif