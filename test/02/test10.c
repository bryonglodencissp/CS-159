#include <stdio.h>

int main() {

  int x = 15;
  int y = 25;
  int z = 0;

  do {
    z += y / x;

    y += 2;
    x += 5;

  } while(y++ / x++ || z++ % 5 != 0);

  printf("x: %d y: %d z: %d\n", x, y, z);
}
