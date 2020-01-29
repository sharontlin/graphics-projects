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

void draw_line_low(int x0, int y0, int x1, int y1, screen s, color c) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = 2*dy - dx;
    int j = y0;

    for (int i = x0; i < x1; i++) {
        plot(s, c, i, j);
        if (D > 0) {
            j = j + yi;
            D = D - 2*dx;
        }
        D = D + 2*dy;
    }
}

void draw_line_high(int x0, int y0, int x1, int y1, screen s, color c) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = 2*dx - dy;
    int i = x0;

    for (int j = y0; j < y1; j++) {
        plot(s, c, i, j);
        if (D > 0) {
            i = i + xi;
            D = D - 2*dy;
        }
        D = D + 2*dx;
    }
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

    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1) {
            draw_line_low(x1, y1, x0, y0, s, c);
        } else {
            draw_line_low(x0, y0, x1, y1, s, c);
        }
    } else {
        if (y0 > y1) {
            draw_line_high(x1, y1, x0, y0, s, c);
        } else {
            draw_line_high(x0, y0, x1, y1, s, c);
        }
    }
}
