#include<stdio.h>

#define SIZE 9

int main()
{
  int i;
  int x[SIZE] = {13, 11, 22, 32, 15, 23, 28, 19, 18};

  for(i = 0; i < SIZE; i++)
  {
    x[i] -= x[SIZE - i - 1];
    x[SIZE - i - 1] += x[i];
    x[i] = x[SIZE - i - 1] - x[i];
  }

  printf("x[2] = %d\n", x[2]);
  printf("x[4] = %d\n", x[4]);
  printf("x[8] = %d\n", x[8]);
}
