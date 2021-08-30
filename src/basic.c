#include <stdio.h>
#include <string.h>

const int WIDTH = 60;
const int HEIGHT = 20;

// frame buffer
char fb[HEIGHT][WIDTH];

void drawFrame() {
  printf("\x1b[H");
  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
      putchar(fb[j][i]);
    }
    putchar('\n');
  }
}

int main() {
  memset(fb, ' ', WIDTH * HEIGHT);

  // top and bottom border.
  for (int i = 0; i < WIDTH; i++) {
    fb[0][i] = '*';
    fb[HEIGHT - 1][i] = '*';
  }
  
  // left and right border.
  for (int i = 0; i < HEIGHT; i++) {
    fb[i][0] = '*';
    fb[i][WIDTH - 1] = '*';
  }  

  drawFrame();
}
