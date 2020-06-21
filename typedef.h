#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

typedef char * String ;
typedef String * String_ptr;
typedef struct
{
  String_ptr lines;
  int number;
} Dynamic_strings;
typedef Dynamic_strings * Dynamic_strings_ptr;

typedef struct
{
  String PS1;
}Env_data;

typedef Env_data * Env_data_ptr;

typedef struct
{
  FILE * input;
  FILE * output;
} Process_stream;

typedef Process_stream * Process_stream_ptr;

#endif