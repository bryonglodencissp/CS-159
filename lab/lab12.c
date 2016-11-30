#include <stdio.h>

#define MAX_CLASS 30

int getExiting(int []);
int getReturning(int []);

void findExitNoReturn(int [], int [], int, int);
void findReturnNoExit(int [], int [], int, int);

int main()
{

  int exiting [MAX_CLASS] = {0};
  int returning [MAX_CLASS] = {0};

  int exitingLength = getExiting(exiting);
  int returningLength = getReturning(returning);

  findExitNoReturn(exiting, returning, exitingLength, returningLength);
  findReturnNoExit(exiting, returning, exitingLength, returningLength);
  
  return(0);
}

int getExiting(int array [])
{

  int i = -1; // Iterator
  printf("\nEnter set of exiting students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  return(i + 1);
}

int getReturning(int array [])
{

  int i = -1; // Iterator
  printf("Enter set of returning students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  return(i + 1);
}

void findExitNoReturn(int exiting [], int returning [], int exitLen, int returnLen)
{

}

void findReturnNoExit(int exiting [], int returning [], int exitLen, int returnLen)
{

}
