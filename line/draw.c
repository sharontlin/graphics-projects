#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    if (x0 > x1) {
        int tmp = x0;
        x0 = x1;
        x1 = tmp;
    }

    if (y0 > y1) {
        int tmp = y0;
        y0 = y1;
        y1 = tmp;
    }

    float deltax = x1-x0;
    float deltay = y1-y0;
    float deltaerr = fabsf(deltay/deltax);
    float error = 0.0;

    int j = y0;
    for (int i = x0; i < x1; i++) {
        plot(s, c, i, j);
        error = error + deltaerr;
        if (error >= 0.5) {
            j = j + sign(deltay) * 1;
            error = error - 1.0;
        }

    }
}
