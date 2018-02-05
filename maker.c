#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
  int fd = open("image.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  char *buf = "P3 500 500 255 ";
  write(fd, buf, strlen(buf));
  char triple[2000];
  int x;
  int y;
  int r;
  int g;
  int b;
  for (x = 0; x < 500; x++) {
    for (y = 0; y < 500; y++) {
        r = (-1 * x) % 256;
        g = y % 256;
        b = (x * y) % 256;
        sprintf(triple, "%d %d %d ", r, g, b);
        write(fd, triple, strlen(triple));
    }
  }
  return 1;
}
