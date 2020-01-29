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
  c.blue = MAX_COLOR/2;

  clear_screen(s);

  for (int i = 0; i < 550; i = i + 20) {
    draw_line(i,400,i,5, s, c);
    draw_line(i+10,300,i+10,5, s, c);
  }

  display(s);
  save_extension(s, "lines.png");
}
