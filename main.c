#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c; 

  clear_screen(s);
  

  struct matrix *edges;
  struct matrix *m1;
  struct matrix *m2;

  edges = new_matrix(4, 2);
  m1 = new_matrix(4,4);
  m2 = new_matrix(4,4);

  printf("Testing add_edge. Adding (1,2,3), (4,5,6) edges = \n");

  add_edge(edges, 1, 2 ,3, 4, 5, 6);
  print_matrix(edges); 

  printf("Testing add_edge. Adding (1,2,3), (4,5,6) (7,8,9), (10, 11, 12) m2 = \n");

  add_edge(m2, 1, 2 ,3, 4, 5, 6);
  add_edge(m2, 7, 8, 9, 10, 11, 12);
  print_matrix(m2); 

  printf("Testing indent. m1 = \n");

  ident(m1);
  print_matrix(m1);

  printf("Testing Matrix mult. m1 * edges = \n");

  matrix_mult(m1, edges);
  print_matrix(edges);

  printf("Testing Matrix mult. m2 * edges = \n");

  matrix_mult(m2, edges);
  print_matrix(edges);


  free_matrix( edges );

  struct matrix *drawingr;
  struct matrix *drawingg;
  struct matrix *drawingb; 
  drawingr = new_matrix(4,2);
  drawingg = new_matrix(4,2);
  drawingb = new_matrix(4,2);

  double pointsx0[16]; 
  double pointsy0[16];

  double pointsx1[16]; 
  double pointsy1[16];

  double pointsx2[16]; 
  double pointsy2[16];

  int i;
  for(i = 0; i < 16; i++) 
  {

      pointsx0[i] = 200 * cos((i * 2 * M_PI) / 16.0) + 250;
      pointsy0[i] = 200 * sin((i * 2 * M_PI) / 16.0) + 250;

      pointsx1[i] = 200 * cos(((i * 2 * M_PI) / 16.0) - (2 * M_PI) / 3) + 250;
      pointsy1[i] = 200 * sin(((i * 2 * M_PI) / 16.0) - (2 * M_PI) / 3) + 250;

      pointsx2[i] = 200 * cos(((i * 2 * M_PI) / 16.0) + (2 * M_PI) / 3) + 250;
      pointsy2[i] = 200 * sin(((i * 2 * M_PI) / 16.0) + (2 * M_PI) / 3) + 250;

  }

  int j; 
  for (j = 0; j < 16; j ++)
  {
    int k;
    for (k = j + 1; k < 16; k++) {
      add_edge(drawingr, pointsx0[j], pointsy0[j], 0, pointsx0[k], pointsy0[k], 0);
      add_edge(drawingg, pointsx1[j], pointsy1[j], 0, pointsx1[k], pointsy1[k], 0);
      add_edge(drawingb, pointsx2[j], pointsy2[j], 0, pointsx2[k], pointsy2[k], 0);
    }
  }

  c.red = 255; 
  c.green = 0; 
  c.blue = 0;
  draw_lines(drawingr, s, c);
  c.red = 0; 
  c.green = 255; 
  c.blue = 0;
  draw_lines(drawingg, s, c);
  c.red = 0; 
  c.green = 0; 
  c.blue = 255;
  draw_lines(drawingb, s, c);

  display(s);
  save_extension(s, "ball.png");
}  
