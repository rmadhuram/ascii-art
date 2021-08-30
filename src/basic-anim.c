#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
  int i = 0;
  while (1) {
    memset(fb, (i++  % 32) + 65, WIDTH * HEIGHT);
    drawFrame();
    usleep(250*1000);
  }
}
