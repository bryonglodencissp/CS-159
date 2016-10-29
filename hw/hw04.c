
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 4
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M. - 1:20 P.M., SC 189
*
*  Program Description: This program determines the day of the week of a day in a year
*                       and then checks when the next tuesday occur if any.
*
***************************************************************************/

#include <stdio.h>

#define DNE 0
#define TUESDAY 2

void getYear(int*);
void getDay(int*, int);
int getDayOfWeek(int, int);
int getDecemberThirtyFirst(int);
int getNextTuesday(int, int, int);
void printResults(int, int, int);
void printDay(int);

int main()
{

  int year; // Year Entered By User
  int dayNum; // Day Entered by User
  int dayOfWeek; // Day of the Week
  int nextTuesday; // Days till Next Tuesday
  
  getYear(&year);
  getDay(&dayNum, year);

  dayOfWeek = getDayOfWeek(year, dayNum);
  nextTuesday = getNextTuesday(year, dayNum, dayOfWeek);
  
  printResults(dayNum, dayOfWeek, nextTuesday);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getYear
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* year; // The year to use from user input.
*
*     Function Description: Gets the year from the user input
*
***************************************************************************/

void getYear(int* year)
{
  printf("\nEnter the year: ");
  scanf("%d", year);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getDay
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* day; // The day of the year (from 1 - 365/6)
*       2. int year; // The year to determine if leap
*     Function Description: Get the day from the user input
*
***************************************************************************/

void getDay(int* day, int year)
{
  int yearDays; // Days in a year
  yearDays = 365 + ((!(year % 4) && (year % 100)) || !(year % 400));

  printf("Enter the day number [1 - %d]: ", yearDays);
  scanf("%d", day);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getDayOfWeek
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year to calculate day of week
*       2. int day; // The day to calculate day of week
*
*     Function Description: Determines the day of the week
*
***************************************************************************/

int getDayOfWeek(int year, int day) 
{
  return((day + getDecemberThirtyFirst(year)) % 7);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getDecemberThirtyFirst
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year to find the day before the first day of the year
*
*     Function Description: Find december 31st of the previous year to calculate day of week
*
***************************************************************************/

int getDecemberThirtyFirst(int year) 
{
  return(((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getNextTuesday
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year from STDIN
*       2. int day; // The day of the year
*       3. int dayOfWeek; // The day of the week
*
*     Function Description: Gets the next tuesday in a year. Return 0 if no tuesday
*
***************************************************************************/

int getNextTuesday(int year, int day, int dayOfWeek)
{
  int dayTillNext; // Days till Next Tuesday
  int dayInYear;   // Total Amount of Days

  dayTillNext = (9 - dayOfWeek) % 7;
  dayTillNext = dayTillNext == 0 ? 7 : dayTillNext;
  
  dayInYear = 365 + ((!(year % 4) && (year % 100)) || !(year % 400));
  return((day + dayTillNext) > dayInYear ? 0 : dayTillNext);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printResults
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day; // Day of the year
*       2. int dayOfWeek; // Day of the week
*       3. int nextTuesday; // The amount of days till the next tuesday
*
*     Function Description: Prints the results
*
***************************************************************************/

void printResults(int day, int dayOfWeek, int nextTuesday)
{
  char plural; // Determines if an 's' is needed

  if(dayOfWeek == TUESDAY)
  {
    printf("\nThe specified day number (%d) is a Tuesday.\n\n", day);
    return;
  }

  printf("\nThe day number entered (%d) is a ", day);
  printDay(dayOfWeek);

  if(nextTuesday == DNE)
  {
    printf(".\nThere are no more Tuesdays remaining in the year.\n\n"); 
  }
  else
  {
    plural = 's' * (dayOfWeek != 1);
    printf(".\nThe next Tuesday will occur in %d day%c.\n\n", nextTuesday, plural);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printDay
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day; // The day of the week
*
*     Function Description: Prints the corresponding day to the console
*
***************************************************************************/

void printDay(int day)
{
  switch(day) 
  {
    case 0:
      printf("Sunday");
      break;
    case 1:
      printf("Monday");
      break;
    case 2:
      printf("Tuesday");
      break;
    case 3:
      printf("Wednesday");
      break;
    case 4:
      printf("Thursday");
      break;
    case 5:
      printf("Friday");
      break;
    case 6:
      printf("Saturday");
    default:
      break;
  }
}
