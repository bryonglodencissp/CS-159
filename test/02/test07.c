#include <stdio.h>

int main() {

  int a;
  int b;
  int c;
  int d = 0;

  for(a = 64; a > 1; a /= 2) {
    for(b = 1; b < 27; b *= 3) {
      for(c = 2; c < 10; c += 2) {
	d++;
      }
    }
  }

  printf("sum %d\n", a + b + c);
  printf("d: %d\n", d);
}
