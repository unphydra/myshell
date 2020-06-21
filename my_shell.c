#include "my_shell.h"

void remove_new_line(String cmd)
{
  for (size_t i = 0; cmd[i]!='\0'; i++)
  {
    if (cmd[i]=='\n')
    {
      cmd[i] = '\0';
    }
  }
}

int main(void)
{
  Env_data_ptr env = parse_lines_of_env();
  while (1)
  {
    parse_ps_one(env->PS1);
    signal(SIGINT,SIG_IGN);
    char * command = malloc(255);
    Process_stream ps = {stdin,stdout};
    fgets(command,255,ps.input);
    remove_new_line(command);

    if (strlen(command)==0)
    {
      continue;
    }
    Dynamic_strings_ptr args = string_spliter(command, " ");

    if (strcmp(args->lines[0],"cd")==0)
    {
      cd(args->lines);
      continue;
    }
    if (strcmp(args->lines[0],"exit")==0) exit(0);
    call_child(args->lines,ps);
  }
}