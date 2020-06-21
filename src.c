#include "my_shell.h"
#include "typedef.h"

void call_child(String_ptr args)
{
  int pid = fork();
  if (pid == 0)
  {
    signal(SIGINT,SIG_DFL);
    int result = execvp(args[0],args);
    if (result < 0)
    {
      printf("my-shell: command not found: %s\n",args[0]);
    }
    
    exit(0);
  }
  else
  {
    wait(NULL);
  }
  printf("\n");
}

String_ptr string_spliter(String command, String spliter)
{
  int len = strlen(command);
  String_ptr args = malloc(sizeof(String) * len);
  int count = 0;
  String token = strtok(command, spliter);
  args[count++] = token;
  do {
    token = strtok(NULL, spliter);
    args[count++] = token;
   }while( token != NULL );
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