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

  draw_line(100,800,5,5, s, c);

  display(s);
  save_extension(s, "lines.png");
}
