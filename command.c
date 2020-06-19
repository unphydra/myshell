#include "command.h"

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