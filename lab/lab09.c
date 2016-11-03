/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	      1. Atif Niyaz aniyaz@purdue.edu
*       2. Ittichot Suwanmungkool isuwanmu@purdue.edu
*       3. Canyu Yang yang1083@purdue.edu
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
*  Program Description: This program allows the user to determine from a
*                       starting value the next value that meets the 
*                       requirements based on the option that they selected
*                       initially in the program. The next value is then
*                       displayed out to the user.
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

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printMenuAndGetInput
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwanmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* option; // The user's option
*       2. int* start;  // The starting value 
*
*     Function Description: Prints the menu and gets input which has been
*                           validated within the function.
*
***************************************************************************/

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

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getValue
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwangmungkool, Canyu Yang
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int option; // The user's option
*       2. int start; // The starting value
*       3.
*
*     Function Description: Gets the next integer that meets the requirements
*                           based on the user's option. 
*
***************************************************************************/

int getValue(int option, int start)
{
  do 
  {
    start++;
  }
  while(!count(option, start));
  
  return(start);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: count
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwangmungkool, Canyu Yang
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int option; // Option selected
*       2. int value; // The value to analyze
*
*     Function Description: Returns if the value that is passed by fits
*                           the requirements based on the option that
*                           the user selected. Does this for each value.
*
***************************************************************************/

int count(int option, int value)
{
  int trio = 0; // 0 if trio doesnt exist, 1 if trio exists
  int duo = 0; // 0 if duo doesnt exist, 1 if duo exists

  while(value != 0)
  {
    duo += (value % 10) == (value / 10 % 10);
    trio += (value % 10) == (value / 10 % 10) && (value / 10 % 10) == (value / 100 % 10);
    
    value /= 10;
  }

  return((option - duo) == 1 && (option == 3 ? trio == 1 : !trio));
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printResults
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwangmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int option; // The user's option
*       2. int value; // The next integer that meets option requirements
*
*     Function Description: Prints the results to the terminal.
*
***************************************************************************/

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
