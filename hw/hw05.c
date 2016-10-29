/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 5
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M. - 1:30 P.M., SC 189
*
*  Program Description: This program determines the largest value that has
*                       the most digits of a digit that is desired by the user from a dataset.
*                       The dataset is determined from min, max, and random seed.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void validate(int*, int*, int*, int*);
void findLargest(int, int, int, int);
int determineDig(int, int);

int main()
{

  int dataSize; // Size of the Data
  int lowest; // Lowest Value to Generate
  int highest; // Highest Value to Generate
  int digit; // Digit to Find

  validate(&dataSize, &lowest, &highest, &digit);
  findLargest(dataSize, lowest, highest, digit);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: validate
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* dataSize; // Size of the data set
*       2. int* lowest; // Min number in range to generate
*       3. int* highest; // Max number in range to generate
*       4. int* digit; // Specific digit to find
*
*     Function Description: Validates and stores the input of the user
*
***************************************************************************/
void validate(int* dataSize, int* lowest, int* highest, int* digit)
{
  int i; // For-loop iterator
  int randGen; // Rand-Gen seed
  
  printf("\n");

  for(i = 0; i < 5; i++) {
    switch(i)
    {
      case 0:
        printf("Enter seed to use for random number generation: ");
	scanf("%d", &randGen);
	break;
      case 1:
	printf("Enter desired data set size: ");
	scanf("%d", dataSize);
	break;
      case 2:
	printf("Enter lowest value to be generated: ");
	scanf("%d", lowest);
	break;
      case 3:
        printf("Enter highest value to be generated: ");
        scanf("%d", highest);
	break;
      case 4:
        printf("Enter digit to locate: ");
        scanf("%d", digit);
	break;
    }
    
    if(i == 0 && randGen <= 0) 
    {
      printf("\nError! Seed must be a positive value!\n\n");
      i--;
    }
    else if(i == 1 && *dataSize <= 0)
    {
      printf("\nError! Data set size must be a positive value!\n\n");
      i--;
    }
    else if(i == 2 && *lowest <= 0)
    {
      printf("\nError! Lowest acceptable value is 1.\n\n");
      i--;
    }
    else if(i == 3 && *highest <= *lowest)
    {
      printf("\nError! Highest value must be greater than %d.\n\n", *lowest);
      i--;
    }
    else if(i == 4 && (*digit < 1 || *digit > 9))
    {
      printf("\nError! Digit must be in the range 1-9.\n\n");
      i--;
    }
  }

  srand(randGen);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: findLargest
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int dataSize; // Size of the dataset
*       2. int min; // Minimum number to gen
*       3. int max; // Maximum number to gen
*       4. int digit; // Digit to find
*
*     Function Description: Find the largest number with the max digits
*
***************************************************************************/
void findLargest(int dataSize, int min, int max, int digit)
{
  int maxDig; // Maximum digits found
  int maxVal; // Maximum value

  int i; // For-loop iterator
  
  int currVal; // Current value
  int currDig; // Current digits

  maxDig = 0; // Initialize max digits
  maxVal = 0; // Initialize max value

  for(i = 0; i < dataSize; i++)
  {
    currVal = rand() % (max - min + 1) + min;
    currDig = determineDig(currVal, digit);

    if((currDig > maxDig) || (currDig == maxDig && currVal > maxVal))
    {
      maxDig = currDig;
      maxVal = currVal;
    }
  }

  printf("\nLargest value (%d) in data set with the most %d's (%d).\n\n", maxVal, digit, maxDig);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: determineDig
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int num; // Number to analyze
*       2. int digit; // The digit to find
*
*     Function Description: Determine the amount of valid digits  in a said number
*
***************************************************************************/
int determineDig(int num, int digit)
{
  int numDig; // Number of digits found
  numDig = 0; // Initialize number of digits

  while(num != 0)
  {
    if(num % 10 == digit)
      numDig++;

    num /= 10;
  }  

  return(numDig);
}
