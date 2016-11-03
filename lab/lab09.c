/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Atif Niyaz aniyaz@purdue.edu
*        2. Ittichot Suwanmungkool isuwanmu@purdue.edu
*        3. Canyu Yang yang1083@purdue.edu
*
*  Lab #: 9
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

void printMenuAndGetInput(int*, int*);
int getValue(int, int);
int count(int, int);
void printResults(int, int);

int main()
{

  int option = 0; // The option the user wants
  int start = 0; // Starting integer of count
  
  printMenuAndGetInput(&option, &start);
  printResults(option, getValue(option, start));

  return(0);
}

void printMenuAndGetInput(int* option, int* start) 
{
  printf("\n1. No adjacent digits the same.\n2. A single pair of adjacent digits the same.\n3. A single trio of adjacent digits the same.\n\n");

  do 
  {
    
    printf("Enter desired option: ");
    scanf("%d", option);
    
    if(*option <= 0 || *option > 3)
    {
      printf("\nError! Invalid option selected!!\n\n");
    }
  } 
  while(*option <= 0 || *option > 3);

  do
  {

    printf("Enter starting integer: ");
    scanf("%d", start);

    if(*start < 0)
    {
      printf("\nError! Non-negative values only!!\n\n");
    }
  }
  while(*start < 0);
}

int getValue(int option, int start)
{
  do 
  {
    start++;
  }
  while(!count(option, start));
  
  return(start);
}

int count(int option, int start)
{
  int trio = 0; // 0 if doesnt exist, 1 if exists
  int duo = 0; // 0 if doesnt exist, 1 if exists

  while(start != 0)
  {

    duo += (start % 10) == (start / 10 % 10);
    trio += (start % 10) == (start / 10 % 10) && (start / 10 % 10) == (start / 100 % 10);
    
    start /= 10;
  }

  return((option == 3 && trio == 1 && duo == 2) || (option == 2 && trio == 0 && duo == 1) || (option == 1 && trio == 0 && duo == 0));
}

void printResults(int option, int value)
{
  printf("\nNext larger value with ");
  
  switch(option)
  {
    case 1:
      printf("no two adjacent digits ");
      break;
    case 2:
      printf("only a single pair of digits ");
      break;
    case 3:
      printf("only a single trio of digits ");
  }

  printf("the same is %d.\n\n", value);
}

