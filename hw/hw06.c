/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 06
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M - 1:20 P.M., SC 189
*
*  Program Description: This program calculates how many different prime numbers
*                       can be made up based on adjacent pairs in a specified 
*                       number
*
***************************************************************************/

#include <stdio.h>

#define NUM_INTS 15

void getInput(int[]);
void analyze(int[]);
void analyzeInteger(int);

int main()
{
  int dataSet [NUM_INTS] = {}; // Dataset Array to Analyze (Initialize all Values)

  getInput(dataSet);
  analyze(dataSet);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getInput
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int dataSet []; // The dataSet array to populate
*
*     Function Description: Takes in NUM_INTS integers into an array from
*                           input.
*
***************************************************************************/

void getInput(int dataSet [])
{
  int i; // For-loop Iterator
  
  printf("\nEnter %d integers now: ", NUM_INTS);
  
  for(i = 0; i < NUM_INTS; i++)
  {
    scanf("%d", &dataSet[i]);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: analyze
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int dataSet []; // The data set array to analyze
*
*     Function Description: Takes in NUM_INTS integers and analyzes each
*                           one for primes.
*
***************************************************************************/

void analyze(int dataSet [])
{
  int i; // For-loop iterator

  printf("\nTwo-digit primes found within the data provided:\n\n");

  for(i = 0; i < NUM_INTS; i++)
  {
    analyzeInteger(dataSet[i]);
  }

  printf("\n");
} 

/***************************************************************************
*
*     Function Information
*
*     Name of Function: analyzeInteger
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int value; // Specific Number to Analyze
*
*     Function Description: Takes in a <int> value and analyzes it checking
*                           for primes in each pair. 
*
***************************************************************************/

void analyzeInteger(int value)
{
  int number; // Two digit number to analyze
  int i; // For-loop Iterator
  int primeCount = 0; // Count of how many prime numbers in number

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
