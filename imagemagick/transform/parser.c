#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"


/*======== void parse_file () ==========
Inputs:   char * filename
          struct matrix * transform,
          struct matrix * pm,
          screen s
Returns:

Goes through the file named filename and performs all of the actions listed in that file.
The file follows the following format:
     Every command is a single character that takes up a line
     Any command that requires arguments must have those arguments in the second line.
     The commands are as follows:
         line: add a line to the edge matrix -
               takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
         ident: set the transform matrix to the identity matrix -
         scale: create a scale matrix,
                then multiply the transform matrix by the scale matrix -
                takes 3 arguments (sx, sy, sz)
         translate: create a translation matrix,
                    then multiply the transform matrix by the translation matrix -
                    takes 3 arguments (tx, ty, tz)
         rotate: create a rotation matrix,
                 then multiply the transform matrix by the rotation matrix -
                 takes 2 arguments (axis, theta) axis should be x y or z
         apply: apply the current transformation matrix to the edge matrix
         display: clear the screen, then
                  draw the lines of the edge matrix to the screen
                  display the screen
         save: clear the screen, then
               draw the lines of the edge matrix to the screen
               save the screen to a file -
               takes 1 argument (file name)
         quit: end parsing

See the file script for an example of the file format

IMPORTANT MATH NOTE:
the trig functions int math.h use radian mesure, but us normal
humans use degrees, so the file will contain degrees for rotations,
be sure to conver those degrees to radians (M_PI is the constant
for PI)
====================*/
void parse_file ( char * filename, 
                  struct matrix * transform, 
                  struct matrix * edges,
                  screen s) {

  FILE *f;
  char line[256];
  clear_screen(s);

  color c;
  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;

  if ( strcmp(filename, "stdin") == 0 ) 
    f = stdin;
  else
    f = fopen(filename, "r");
  
  while ( fgets(line, 255, f) != NULL ) {
    struct matrix *transform_matrix = new_matrix(4, 4);
    line[strlen(line)-1]='\0';
    printf(":%s:\n",line);

    if (strcmp(line, "line") == 0) {
      fgets(line, 255, f);
      double x1, y1, z1, x2, y2, z2;
      sscanf(line, "%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
      add_edge(edges, x1, y1, z1, x2, y2, z2);
    } else if (strcmp(line, "ident") == 0) {
      
      ident(transform);
      
    } else if (strcmp(line, "scale") == 0) {

      fgets(line, 255, f);  
      double x, y, z;
      sscanf(line, "%lf %lf %lf", &x, &y, &z);
      transform_matrix = make_scale(x, y, z);
      matrix_mult(transform_matrix, transform);
      
    } else if (strcmp(line, "move") == 0) {
      
      fgets(line, 255, f);  
      double x, y, z;
      sscanf(line, "%lf %lf %lf", &x, &y, &z);
      transform_matrix = make_translate(x, y, z);
      matrix_mult(transform_matrix, transform);
      
    } else if (strcmp(line, "rotate") == 0) {
      
      fgets(line, 255, f);
      char axis = 0;
      double theta = 0;

      sscanf(line, "%c %lf", &axis, &theta);
           
      switch(axis) {
      case 'x':
        transform_matrix = make_rotX(theta);
        break;
      case 'y':
        transform_matrix = make_rotY(theta);
        break;
      case 'z':
        transform_matrix = make_rotZ(theta);
        break;
      }
	
      matrix_mult(transform_matrix, transform);
          
    } else if (strcmp(line, "apply") == 0) {
      
      matrix_mult(transform, edges);
      
    } else if (strcmp(line, "display") == 0) {

      draw_lines(edges, s, c);
      display(s);
      
    } else if (strcmp(line, "clear") == 0) {

      clear_screen(s);
      
    } else if (strcmp(line, "save") == 0) {

      char file;
      fgets(line, 255, f);
      save_extension(s, line);
      
    }
  }
}
  
