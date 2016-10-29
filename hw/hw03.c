
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 3
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
*  Program Description: This program allows one to pick 3 or pick 4 in 
*                       a lottery. The user selects the choice and then
*                       random numbers between 0-9 are displayed.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void setRandSeed();
int getChoice();
void generateRandom(int);

int main()
{
  setRandSeed();
  generateRandom(getChoice());

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: setRandSeed
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Function Description: Set the random seed for the random number generator
*
***************************************************************************/

void setRandSeed()
{
  int seed; // Seed to use for Random

  printf("\nEnter seed to use for random number generation: ");
  scanf("%d", &seed);
  
  srand(seed);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getChoice
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Function Description: Get the choice of which amount of numbers that the user should generate
*
***************************************************************************/

int getChoice() 
{
  int choice; // User Choice 

  printf("\nDaily State Lottery\n1. Pick 3 Draw\n2. Pick 4 Draw\n\nEnter your selection: ");
  scanf("%d", &choice);
  return(choice);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: generateRandom
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int choice; // The choice that the user selected
*
*     Function Description: Generate random numbers based on the choice that the
*                           user selected and prints them out.
*
***************************************************************************/

void generateRandom(int choice)
{
  int rand_one; // First Random Number
  int rand_two; // Second Random Number
  int rand_three; // Third Random Number
  int rand_four; // Fourth Random Number
  
  rand_one = rand() % 10;
  rand_two = rand() % 10;
  rand_three = rand() % 10;
  rand_four  = (rand() % 10 + 48) * abs(choice - 1) + 32 * abs(choice - 2) ;
  
  printf("\nYour lottery numbers: %d %d %d %c\n\n", a, b, c, d);
}
