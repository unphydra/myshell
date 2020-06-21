#include "my_shell.h"

int main(void)
{
  Env_data_ptr env = parse_lines_of_env();
  while (1)
  {
    parse_ps_one(env->PS1);

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