/***************************************************************************
 *
 *  Programmers and Purdue Email Addresses:
 *  1. Atif Niyaz       aniyaz@purdue.edu
 *  2. Joshua Zhao      zhao662@purdue.edu
 *  3. Luca von Lintel  mvonlint@purdue.edu 
 *
 *  Lab #: 06
 *
 *  Academic Integrity Statement:
 *
 *       We have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have we provided access 
 *       to our code to another. The project we are submitting
 *       is our own original work.
 *
 *  Lab Division and Section: Wednesday, 11:30 A.M. to 1:20 P.M., SC 189
 *
 *  Program Description: Calculates the word form of a given number from -99,999 to 99,999
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define THOUSANDS 2
#define HUNDREDS 1
#define ONES 0
#define ZERO 0

void getNumber(int*);
void determineMinus(int*);
void separate(int, int);
void convertZeroToNinetyNine(int);

int main()
{

  int num; // Number to Convert

  getNumber(&num);

  determineMinus(&num);
  separate(num, THOUSANDS);
  separate(num, HUNDREDS);
  separate(num, ONES);

  return(ZERO);
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: getNumber
 *
 *     Programmer's Name: Joshua Zhao, Atif Niyaz, Luca von Lintel
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int* number; // The number to store
 *      
 *     Function Description: Get the number from the user input
 *
 ***************************************************************************/
void getNumber(int* number)
{
  printf("\nPlease enter the number in standard form: ");
  scanf("%d", number);
  printf("\nConversion to word form: ");
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: determineMinus
 *
 *     Programmer's Name: Joshua Zhao, Atif Niyaz, Luca von Lintel
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int* number; // Number to analyze for negative
 *       
 *     Function Description: Determines if the number is negative and prints out "minus". 
 *                           Then sets the value of number to a positive number.
 *
 ***************************************************************************/
void determineMinus(int* number)
{
  if(*number < ZERO)
  {
    printf("minus ");
  }
  
  *number = abs(*number);
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: separate
 *
 *     Programmer's Name: Joshua Zhao, Atif Niyaz, Luca von Lintel
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int num; // Number to analyze
 *       2. int place; // Place (i.e. Thousands, Hundres, Ones)
 *       
 *     Function Description: Seperates the number based on the place (i.e. Thousands, Hundreds, Ones)
 *                           Prints out the appropriate string for the number
 *
 ***************************************************************************/
void separate(int num, int place)
{

  if(num == ZERO && place == ONES)
  {
    printf("zero\n\n");
    return;
  }

  if(place == THOUSANDS)
  {
    num /= 1000;
  }
  else if(place == HUNDREDS)
  {
    num = (num % 1000) / 100;
  }
  else
  {
    num %= 100;
  }
 
  if(num == ZERO)
  {
    if(place == ONES)
    {
      printf("\n\n");
    }
    return;
  }

  convertZeroToNinetyNine(num);

  if(place == THOUSANDS)
  {
    printf(" thousand ");
  }
  else if(place == HUNDREDS)
  {
    printf(" hundred ");
  } 
  else if(place == ONES)
  {
    printf("\n\n");
  }
} 

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: convertZeroToNinetyNine
 *
 *     Programmer's Name: Joshua Zhao, Atif Niyaz, Luca von Lintel
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int number; // Number from 0 to 99 to convert
 *       
 *     Function Description: Takes a number from 0 to 99 and converts it to a string
 *
 ***************************************************************************/
void convertZeroToNinetyNine(int number) 
{

  char useHyphen; // Determine if we need hyphen
  useHyphen = '-' * (number > 20);

  switch(number / 10) 
  {
    case 9:
      printf("ninety");
      break;
    case 8: 
      printf("eighty");
      break;
    case 7:
      printf("seventy");
      break;
    case 6:
      printf("sixty");
      break;
    case 5:
      printf("fifty");
      break;
    case 4:
      printf("forty");
      break;
    case 3:
      printf("thirty");
      break;
    case 2:
      printf("twenty");
      break;
    default:
      break;
  }

  if((number > 20 || number < 10) && number % 10 != 0)
  {
    printf("%c", useHyphen);

    switch(number % 10)
    {
      case 9:
        printf("nine");
        break;
      case 8:
        printf("eight");
        break;
      case 7:
        printf("seven");
        break;
      case 6: 
        printf("six");
        break;
      case 5:
        printf("five");
        break;
      case 4:
        printf("four");
        break;
      case 3:
        printf("three");
        break;
      case 2:
        printf("two");
        break;
      case 1:
        printf("one");
        break;
    } 
  } 
  else if(!(number > 19 || number < 10))
  {
    switch(number)
    {
      case 15:
        printf("fifteen");
        break;
      case 13:
        printf("thirteen");
        break;
      case 12:
        printf("twelve");
        break;
      case 11:
        printf("eleven");
        break;
      case 10:
        printf("ten");
        break;
      default:
        convertZeroToNinetyNine(number % 10);
        printf("teen");
	break;
    }
  }
}
