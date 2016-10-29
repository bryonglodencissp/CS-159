/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Luca von Lintel mvonlint@purdue.edu
*	 2. Joshua Zhao zhao662@purdue.edu
*	 3. Atif Niyaz aniyaz@purdue.edu
*
*  Lab #: 8
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M. - 1:30 P.M., SC 189
*
*  Program Description: This program accepts a user input for a random number 
*                       generation seed and data set amount which is used to
*                       generate numbers and then a count is taken for how each
*                       pair is even or odd.
*
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void setSeed();
void generate(int*, int*, int*, int*);
void generatePair(int*, int*, int*, int*);
void printResults(int, int, int, int);

int main()
{

  int ee = 0; // Count of Even / Even #s
  int eo = 0; // Count of Even / Odd #s
  int oe = 0; // Count of Odd / Even #s
  int oo = 0; // Count of Odd / Odd #s
 
  setSeed();
  generate(&ee, &eo, &oe, &oo);
  printResults(ee, eo, oe, oo);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: setSeed
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line): None
*
*     Function Description: Sets the seed for the whole program
*
***************************************************************************/

void setSeed() 
{
  int seed = 0; // The seed to set for the program

  printf("\n");

  do 
  {
    printf("Enter seed value: ");
    scanf("%d", &seed);
    
    if(seed <= 0)
    {
      printf("\nError! Positive integer values only!!\n\n");
    }
  }
  while(seed <= 0);

  srand(seed);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printResults
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int ee; // Even Even Count
*       2. int eo; // Even Odd Count
*       3. int oe; // Odd Even Count
*       4. int oo; // Odd Odd Count
*
*     Function Description: Prints the results to the terminal
*
***************************************************************************/

void printResults(int ee, int eo, int oe, int oo)
{
  printf("\n -Generated Results-\nEven/Even:%10d\nEven/Odd:%11d\nOdd/Even:%11d\nOdd/Odd:%12d\n\n", ee, eo, oe, oo);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: generate
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* ee; // Even Even Count
*       2. int* eo; // Even Odd Count
*       3. int* oe; // Odd Even Count
*       4. int* oo; // Odd Odd Count
*
*     Function Description: Generates a set number of random pairs and determines if odd or even
*
***************************************************************************/

void generate(int* ee, int* eo, int* oe, int* oo)
{
  int reps = 0; // Repetitions of the Program
  int i; // Iterator

  do 
  {
    printf("Enter number of pairs to generate: ");
    scanf("%d", &reps);
    
    if(reps <= 0)
    {
      printf("\nError! Positive integer values only!!\n\n");
    }
  }
  while(reps <= 0);

  for(i = 0; i < reps; i++)
  {
    generatePair(ee, eo, oe, oo);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: generatePair
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* ee; // Even Even Count
*       2. int* eo; // Even Odd Count
*       3. int* oe; // Odd Even Count
*       4. int* oo; // Odd Odd Count
*
*     Function Description: Generate one pair of random numbers
*
***************************************************************************/

void generatePair(int* ee, int* eo, int* oe, int* oo)
{
  
  int numOne; // First Number Generated
  int numTwo; // Second Number Generated

  numOne = rand() % 1000000 + 1;
  numTwo = rand() % 1000000 + 1;

  *ee += !(numOne % 2) && !(numTwo % 2);
  *eo += !(numOne % 2) && (numTwo % 2);
  *oe += (numOne % 2) && !(numTwo % 2);
  *oo += (numOne % 2) && (numTwo % 2);
}
