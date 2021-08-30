#include <stdio.h>
#include <string.h>
#include <math.h>

const int WIDTH = 80;
const int HEIGHT = 20;

// frame buffer
char fb[HEIGHT][WIDTH];

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
  memset(fb, ' ', WIDTH * HEIGHT);

  for (int i = 0; i < WIDTH; i++) {
    int y = 10 - (int) 8 * sin(i * 5 * 0.0174533 );
    fb[y][i] = '*';
  }

  render();
}
