#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int A, B, d, m;
  //vertical line
  if (x1 - x0 == 0){
    while (y0 <= y1){
      plot(s,c,x0,y0);
      y0++;
    }
  }
  //horizontal line
  else if (y1 - y0 == 0){
    while (x0 <= x1){
      plot(s,c,x0,y0);
      x0++;
    }
  }
  else{
    m = (y1 - y0) / (x1 - x0);
    printf("m = %d\n",m);
    A = y1 - y0;
    B = -(x0 - x1);
    //octant 1, 0<m<1
    if (0 < m && m < 1){
      d = 2*A + B;
      while (x0 <= x1){
	plot(s,c,x0,y0);
	if (d > 0){
	  y0++;
	  d+=2*B;
	}
	x0++;
	d+=2*A;
      }
    }
    //octant 2, m>1
    if (m > 1){
      d = A + 2*B;
      while (y0 <= y1){
	plot(s,c,x0,y0);
	if (d < 0){
	  x0++;
	  d+=2*A;
	}
	y0++;
	d+=2*B;
      }
    }
    //octant 7, m<-1
    if (m < -1){
      d = A - 2*B;
      while ( y0 >= y1){
	plot(s,c,x0,y0);
	if (d > 0){
	  x0--;
	  d-=2*A;
	}
	y0--;
	d-=2*B;
      }
    }
    //octant 8, -1<m<0
    if (-1 < m && m < 0){
      d = 2*A - B;
      while (x0 <= x1){
	plot(s,c,x0,y0);
	if (d < 0){
	  y0--;
	  d-=2*B;
	}
	x0++;
	d+=2*A;
      }
    }
  }
}

