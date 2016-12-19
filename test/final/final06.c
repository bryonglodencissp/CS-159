#include<stdio.h>

int main()
{
  int x[2][3] =
  {
    {1, 3, 5},
    {2, 4, 6}
  };

  printf("Value 1: %d\n", x[1][1]);
  printf("Value 2: %d\n", x[0][3]);

  return(0);
}
