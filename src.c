#include "my_shell.h"

void call_child(char** args)
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

char ** get_args(char * command)
{
  int len = strlen(command);
  char ** args = malloc(sizeof(char*)*len);
  int count = 0;
  char * token = strtok(command, " ");
  args[count++] = token;
  do {
    token = strtok(NULL, " ");
    args[count++] = token;
   }while( token != NULL );
  return args;
}
