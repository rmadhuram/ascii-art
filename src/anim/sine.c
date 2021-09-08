#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

const int WIDTH = 80;
const int HEIGHT = 20;

// frame buffer
char fb[HEIGHT][WIDTH];

void drawFrame(t) {
  for (int i = 0; i < WIDTH; i++) {
    int y = 10 - (int) 8 * sin((i * 5 + t) * 0.0174533 );
    fb[y][i] = '*';

    y = 10 - (int) 9 * cos((i * 8 + t) * 0.0174533 );
    fb[y][i] = '.';
  }
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
  int i = 0;
  int t = 0;
  while (1) {
    memset(fb, ' ', WIDTH * HEIGHT);
    drawFrame(t++);
    render();
    usleep(5 * 1000);
  }
}
