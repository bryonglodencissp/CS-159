#include <stdio.h>

int main() {

  int x = 11694;
  int sum = 0;

  do {
    sum += x % 10;
    x /= 10;
  } while(x % sum && x > sum);

  printf("x: %d\n", x);
  printf("sum: %d\n", sum);
}
