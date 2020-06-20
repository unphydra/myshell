#ifndef __FILE_PARSER_H_
#define __FILE_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"

#define LINE_LENGTH sizeof(char) * 80

File_lines_ptr read_file(String);

#endif