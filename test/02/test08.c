#include <stdio.h>

int findValues(int);

int main() {

  int val;

  val = findValues(154);

  printf("val: %d\n", val);
  return(0);
}

int findValues(int n) {

  int seek;
  printf("called\n");
  if(n > 0) {
    
    seek = findValues(n / 5);

    if(n % 2 == 0 && n % 10 > seek) {
      seek = n % 10;
    }
  }

  return(seek);
}
