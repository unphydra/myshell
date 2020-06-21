#ifndef __COLORS_H_
#define __COLORS_H_

#include <stdio.h>
#include <string.h>
typedef void (*Color_fn)(void);
typedef struct 
{
  Color_fn fn_ptr;
  char * name;
} Colors_store;


void bRed ();
void red ();
void bGreen ();
void green ();
void bYellow ();
void yellow ();
void bBlue ();
void blue ();
void bMagenta ();
void magenta ();
void bCyan ();
void cyan ();
void reset ();

void call_color(char *);
#endif