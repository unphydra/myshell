#include "file_parser.h"

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
    return file;
  }
  file->lines[count++] = line;
  }
}