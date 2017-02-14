#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

  //draw_line(0,0,500,500,s,c);
  //draw_line(500,500,0,0,s,c);
  draw_line(250,0,250,500,s,c);//vertical line
  draw_line(0,250,500,250,s,c);//horizontal line
  //draw_line();
  //draw_line();

  display(s);
  save_extension(s, "lines.png");
}  
