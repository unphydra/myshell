#ifndef __FILE_PARSER_H_
#define __FILE_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"

#define LINE_LENGTH sizeof(char) * 80

Dynamic_strings_ptr read_file(String);
Env_data_ptr parse_lines_of_env(void);

#endif