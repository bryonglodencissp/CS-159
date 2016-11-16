#include <stdio.h>

int main() {

  int div;
  int x = 15;
  int total = 0;

  while(x < 24){

    div = 2;
    while(x % div != 0 && div < x / 2) {

      div++;
    }

    if(div < x/2) {

      total += div;
    }

    x++;
  }

  printf("total: %d\n", total);
  printf("div: %d\n", div);
  
}
