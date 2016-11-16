#include <stdio.h>

int main()
{
  int a = 0;
  int b = 11;
  int c = 9;
  int d = 1;

  if(a++ && ++b && c++) {
    d += 2;
  } else if(b++ || ++c) {
    d += 3;
  } else {
    d = 0;
  }

  printf("a: %d d: %d\n", a, d);
  printf("b: %d c: %d\n", b, c);
}
