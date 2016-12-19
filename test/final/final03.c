#include<stdio.h>

void sortData(int[]);
void printArray(int[], int);

int main()
{
  int x[8] = {4, 8, 1, 7, 5, 6, 3, 2};

  sortData(x);

  return(0);
}

void sortData(int x[])
{
  int i;
  int pass;
  int temp;

  for(pass = 1; pass < 8; pass++)
  {
    i = pass;
    temp = x[pass];
    while(i > 0 && temp > x[i - 1])
    {
      x[i] = x[i - 1];
      i--;
    }

    x[i] = temp;
    printArray(x, pass);
  }
}

void printArray(int x[], int pass)
{
  int i;

  printf("Array after pass #%d: ", pass);
  for(i = 0; i < 8; i++)
  {
    printf("%d ", x[i]);
  }

  printf("\n");
}
