#include "colors.h"

void bRed () {
  printf("\033[1;91m");
}

void red () {
  printf("\033[0;91m");
}

void bGreen () {
  printf("\033[1;92m");
}

void green () {
  printf("\033[0;92m");
}

void bYellow () {
  printf("\033[1;93m");
}

void yellow () {
  printf("\033[0;93m");
}

void bBlue () {
  printf("\033[1;94m");
}

void blue () {
  printf("\033[0;94m");
}

void bMagenta () {
  printf("\033[1;95m");
}

void magenta () {
  printf("\033[0;95m");
}

void bCyan () {
  printf("\033[1;96m");
}

void cyan () {
  printf("\033[0;96m");
}

void reset () {
  printf("\033[0m");
}

void call_color(char * color)
{
  Colors_store store[] = {{&bRed,"bRed"},{&red,"red"},{&bGreen,"bGreen"},{&green,"green"},{&bYellow,"bYellow"},{&yellow,"yellow"},{&bBlue,"bBlue"},{&blue,"blue"},{&bMagenta,"bMagenta"},{&magenta,"magenta"},{&bCyan,"bCyan"},{&cyan,"cyan"},{&reset,"res"}};
  for (size_t i = 0; i < 13; i++)
  {
    if (strcmp(store[i].name,color)==0)
    {
      store[i].fn_ptr();
    }
  }
}