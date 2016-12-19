#include<stdio.h>

#define SIZE 8

int main()
{
  int i;
  int j;
  int x[SIZE] = {2, 6, 3, 5, 7, 1, 0, 4};

  for(i = 0; i < SIZE; i++)
  {
    if(x[i] < SIZE)
    {
      j = x[i];
      x[j] += 1;
    }
  }

  printf("x[2] = %d\n", x[2]);
  printf("x[4] = %d\n", x[4]);
  printf("x[7] = %d\n", x[7]);

  return(0);
}
