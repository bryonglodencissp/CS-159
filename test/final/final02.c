#include<stdio.h>

#define SIZE 7

int changeArray(int[], int);

int main()
{
  int x[SIZE] = {9, 5, 4, 2, 1, 3};
  int i;

  for(i = 0; i < SIZE; i++)
  {
    x[i] = changeArray(x, i);
  }

  printf("x[0] = %d\n", x[0]);
  printf("x[3] = %d\n", x[3]);
  printf("x[6] = %d\n", x[6]);

  return(0);
}

int changeArray(int z[], int i)
{
  int j;
  int result = 0;

  for(j = SIZE - 1; j >= 0 + i; j--)
  {
    result = z[j] + result;
  }

  return(result);
}
