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

String_ptr get_args(String command)
{
  int len = strlen(command);
  String_ptr args = malloc(sizeof(String) * len);
  int count = 0;
  String token = strtok(command, " ");
  args[count++] = token;
  do {
    token = strtok(NULL, " ");
    args[count++] = token;
   }while( token != NULL );
  return args;
}
