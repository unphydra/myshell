#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "colors.h"

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

void cd(char ** args)
{
  char path[200];
  if (strncmp(args[1],"/",1)==0)
  {
    chdir(args[1]);
  } else if(strncmp(args[1],"~",1)==0)
  {
    strcat(path,"/Users/step12");
    strcat(path,&args[1][1]);
    chdir(path);
  } else
  {
    getcwd(path,sizeof(path));
    strcat(path,"/");
    strcat(path,args[1]);
    chdir(path);
  }
}

int main(void)
{
  while (1)
  {
    cyan();
    printf("my-shell $ ");
    reset();

    signal(SIGINT,SIG_IGN);
    char command[255];
    gets(command);
    char ** args = get_args(command);

    if (strcmp(args[0],"cd")==0)
    {
      cd(args);
      continue;
    }
    call_child(args);
  }
}