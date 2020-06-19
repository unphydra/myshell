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