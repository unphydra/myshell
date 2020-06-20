#include "file_parser.h"
#include "my_shell.h"

File_lines_ptr read_file(String path)
{
  FILE *fptr;
  if ((fptr = fopen(path, "r")) == NULL) {
      exit(1);
  }

  File_lines_ptr file = malloc(sizeof(File_lines));
  file->lines = malloc(sizeof(String)*100);
  int count = 0;
  
  while(1) 
  {
  String line = malloc(LINE_LENGTH);
  if (fgets(line,LINE_LENGTH,fptr) == NULL)
  {
    fclose(fptr);
    file->number = count;
    return file;
  }
  file->lines[count++] = line;
  }
};

Env_data_ptr parse_lines_of_env(void)
{
  File_lines_ptr file = read_file("mshrc.sh");
  Env_data_ptr env = malloc(sizeof(Env_data));
  for (size_t i = 0; i < file->number; i++)
  {
    String_ptr args = string_spliter(file->lines[i],"=");
    if (strcmp(args[0],"PS1")==0)
    {
      env->PS1 = args[1];
    }
  }
  return env;
}