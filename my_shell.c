#include "my_shell.h"

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
    String_ptr args = string_spliter(command, " ");

    if (strcmp(args[0],"cd")==0)
    {
      cd(args);
      continue;
    }
    if (strcmp(args[0],"exit")==0) exit(0);
    call_child(args);
  }
}