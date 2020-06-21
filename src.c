#include "my_shell.h"
#include "typedef.h"

void call_child(String_ptr args, Process_stream ps)
{  
  int * link = malloc(sizeof(int)*2);
  pipe(link);
  int pid = fork();
  if (pid == 0)
  {
    signal(SIGINT,SIG_DFL);
    dup2(link[1],1);
    close(link[0]);
    close(link[1]);
    int result = execvp(args[0],args);
    if (result < 0)
    {
      printf("my-shell: command not found: %s\n",args[0]);
    }
    exit(result);
  }
  else
  {
    close(link[1]);
    String line = malloc(4096);
    while(read(link[0], line, 4096)){
    fprintf(ps.output,"%s",line);
    memset(line,0,4096);
    }
  }
}

Dynamic_strings_ptr string_spliter(String command, String spliter)
{
  int len = strlen(command);
  Dynamic_strings_ptr args = malloc(sizeof(Dynamic_strings));
  args->lines = malloc(sizeof(String) * len);
  int count = 0;
  String token = strtok(command, spliter);
  args->lines[count++] = token;
  do {
    token = strtok(NULL, spliter);
    args->lines[count++] = token;
   }while( token != NULL );
   args->lines[++count] = NULL;
   args->number = count;
  return args;
}

String get_sub_string(String_ptr source, String dest, char delim)
{
  String_ptr curr = source;
  int count = 0;
  while (**curr != delim)
  {
    dest[count++] = **curr;
    (*curr)++;
  }
  dest[++count] = '\0';
  return dest;
}

void parse_ps_one(String line)
{
  String curr = line;
  while (*curr!='\0')
  { 
    if (*curr == '[')
    {
      String color = malloc(10);
      int count = 0;
      curr++;
      get_sub_string(&curr,color,']');
      call_color(color);
      curr++;
    } else
    {
      String txt = malloc(20);
      get_sub_string(&curr,txt,'[');
      printf("%s",txt);
    }
  }
}