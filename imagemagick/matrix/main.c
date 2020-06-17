#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  struct matrix *m1 = new_matrix(4, 4);
  struct matrix *m2 = new_matrix(4, 4);

  add_edge(m2, 1, 2, 3, 4, 5, 6);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
  print_matrix(m2);

  printf("Testing ident. m1 =\n");
  ident(m1);
  print_matrix(m1);

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  printf("Testing Matrix mult. m1 =\n");
  print_matrix(m1);

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  free_matrix(m1);
  free_matrix(m2);

  screen s;
  color white;
  white.red = 255;
  white.green = 255;
  white.blue = 255;

  clear_screen(s);

  struct matrix * object;

  object = new_matrix(4, 48);

  add_edge(object, 200, 90, 0, 200, 450, 0);
  add_edge(object, 50, 200, 0, 450, 200, 0);

  color c;
  c.red = 130;
  c.green = 75;
  c.blue = 140;

  draw_lines(object, s, c);
  
  free_matrix(object);

  // display(s);
  save_extension(s, "lines.png");

}  
