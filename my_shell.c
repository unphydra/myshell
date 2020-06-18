#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

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

int main(void)
{
  while (1)
  {
    printf("\033[1;31m");
    printf("my-shell $ ");
    printf("\033[0m");

    signal(SIGINT,SIG_IGN);
    char command[255];
    gets(command);
    char ** args = get_args(command);
    int pid = fork();
    if (pid == 0)
    {
      signal(SIGINT,SIG_DFL);
      int result = execvp(args[0],args);
      exit(0);
    }
    else
    {
      wait(NULL);
      printf("\n");
    }
  }
}