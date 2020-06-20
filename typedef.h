#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

typedef char * String ;
typedef String * String_ptr;
typedef struct
{
  String_ptr lines;
  int number;
} File_lines;
typedef File_lines * File_lines_ptr;

#endif