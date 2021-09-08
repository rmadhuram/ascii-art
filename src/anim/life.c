#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

const int WIDTH = 80;
const int HEIGHT = 20;

// frame buffer
char fb[HEIGHT][WIDTH];
char nextSet[HEIGHT][WIDTH];

int drawFrame(t) {
  for (int i=0; i<HEIGHT; i++) {
    for (int j=0; j<WIDTH; j++) {
      
      int current = fb[i][j];
      int neighbors = 0;
      char next = ' ';
      
      /* count the neighbors */
      for (int p = -1; p<=1; p++) {
        for (int q = -1; q <=1; q++) {
          int x = j+q;
          int y = i+p;
          if (x>=0 && x<WIDTH && y>=0 && y<HEIGHT) {
            if (p != 0 || q != 0 ) {
              if (fb[y][x] == '*') {
                neighbors ++;
              }
            }
          }
        } 
      }
      
      if (current == '*') {
        next = '*';
        if (neighbors < 2 || neighbors > 3) {
          next = ' ';
        }
      } else {
        if (neighbors == 3) {
          next = '*';
        }
      }
      
      nextSet[i][j] = next;
    }
  }
 
  int nLive = 0;
  for (int i=0; i<HEIGHT; i++) {
    for (int j=0; j<WIDTH; j++) {
      fb[i][j] = nextSet[i][j];
      if (fb[i][j] == 1) {
        nLive ++;
      }
    }
  }
    
  return nLive;
  
}

void render() {
  printf("\x1b[H");
  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
      putchar(fb[j][i]);
    }
    putchar('\n');
  }
}

int main() {
  int t = 0;
  time_t tm;
      
  /* Intializes random number generator */
  srand((unsigned) time(&tm));

  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
      if ((double)rand() / (double) RAND_MAX < 0.4) {
        fb[j][i] = '*';
      } else {
        fb[j][i] = ' ';     
      }
    }
  }
  while (1) {
    render();
    usleep(300 * 1000);
    drawFrame(t++);
  }
}
