#include<stdio.h>

void changeArray(int [], int);

int main()
{
  int x[8] = {2, 3, 5, 4, 1, 0, 7, 6};
  int i;

  for(i = 0; i < 8; i += 2)
  {
    changeArray(x, i);
  }

  printf("x[0] = %d\n", x[0]);
  printf("x[3] = %d\n", x[3]);
  printf("x[7] = %d\n", x[7]);

  return(0);
}

void changeArray(int y[], int i)
{
  int j;

  for(j = 1; j < 8 - i; j++)
  {
    y[j] += y[j - 1];
  }
}
