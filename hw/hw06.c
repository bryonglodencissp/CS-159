#include <stdio.h>

#define NUM_INTS 15

void getInput(int*);
void analyze(int*);
void analyzeInteger(int);

int main()
{
  int dataSet [NUM_INTS] = {};
  getInput(dataSet);
  analyze(dataSet);

  return(0);
}

void getInput(int* dataSet)
{
  int i;
  printf("\nEnter %d integers now: ", NUM_INTS);
  
  for(i = 0; i < NUM_INTS; i++)
  {
    scanf("%d", &dataSet[i]);
  }
}

void analyze(int* dataSet)
{
  int i;

  printf("\nTwo-digit primes found within the data provided:\n\n");

  for(i = 0; i < NUM_INTS; i++)
  {
    analyzeInteger(dataSet[i]);
  }

  printf("\n");
} 

void analyzeInteger(int value)
{
  int number;
  int i;
  int primeCount = 0;

  printf("%d: ", value);

  while(value >= 10)
  {
    number = (value % 10) + (value / 10 % 10) * 10;
  
    if(number == 1 || number == 2)
    {
      primeCount++;
      printf("%02d ", number);
    }
    else
    {
      for(i = 2; i < number; i++)
      {
        if(number % i == 0)
        {
          i = number;
        }
      }

      if(number == i)
      {
        primeCount++;
        printf("%02d ", number);
      }
    }

    value /= 10;
  }

  if(primeCount == 0)
  {
    printf("No primes found.");
  }

  printf("\n");
}
