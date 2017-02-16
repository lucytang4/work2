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

  //BASICS
  draw_line(0,0,500,500,s,c);//m == 1
  //draw_line(500,500,0,0,s,c);//m == 1
  draw_line(250,0,250,500,s,c);//vertical line
  draw_line(0,250,500,250,s,c);//horizontal line
  draw_line(0,500,500,0,s,c);//m == -1

  //MORE STUFF
  //top left
  int x,y;
  for (x = 0; x < 250; x+=10){
    y = 500 - x;
    draw_line(x,250,250,y,s,c);
  }

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  //bottom right
  for (x = 500; x > 250; x-=10){
    y = 500 - x;
    draw_line(250,y,x,250,s,c);
  }

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;
  
  //bottom left
  for (x = 0; x < 250; x+=10){
    y = x;
    draw_line(x,250,250,y,s,c);
  }

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  //top right
  for (x = 500; x > 250; x-=10){
    y = x;
    draw_line(250,y,x,250,s,c);
  }

  display(s);
  save_extension(s, "lines.png");
}  
