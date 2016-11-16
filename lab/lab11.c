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

#define NUM_INTS 20

int power(int, int);
void getKey(int*);
void getData(int[]);
void secure(int[], int);
void encrypt(int, int);

int main()
{
  int data [NUM_INTS] = {}; // Dataset Array to Analyze (Initialize all Values)
  int key; // Key for the program
  
  getKey(&key);
  getData(data);
  secure(data, key);

  return(0);
}

void getKey(int* key)
{
  
  do
  {
    printf("\nEnter key value: ");
    scanf("%d", key);

    if(*key < 0 || *key >= 10)
    {
      printf("\nError! Key must be a single digit!\n");
    }
  } while(*key < 0 || *key >= 10);
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

void getData(int dataSet [])
{
  int i; // For-loop Iterator
  
  printf("Enter %d data values now: ", NUM_INTS);
  
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

void secure(int dataSet [], int key)
{
  int i; // For-loop iterator

  printf("\n Original  Decrypted\n---------- ----------\n");

  for(i = 0; i < NUM_INTS; i++)
  {
    encrypt(dataSet[i], key);
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

void encrypt(int value, int key)
{

  int valueCopy = value; // Copy of the value
  int powVal = 0; // Power determinator
  int encrypted = 0; // Encrypted number
  
  while(value != 0)
  {
    encrypted += ((value % 10 - key + 10) % 10) * power(10, powVal);
    powVal++;
    value /= 10;
  }

  printf("%10d%0*11d\n", valueCopy, encrypted);
}

int power(int value, int pow) {

  int newValue = 1; // New value;
  int i; // For-loop iterator

  for(i = 0; i < pow; i++) {
    newValue *= value;
  }

  return newValue;
}
