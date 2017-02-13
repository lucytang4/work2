#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = -(x0 - x1);
    int d = 2*A + B;
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

