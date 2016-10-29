/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Luca von Lintel mvonlint@purdue.edu
*	 2. Joshua Zhao zhao662@purdue.edu
*	 3. Atif Niyaz aniyaz@purdue.edu
*
*  Lab #: 7
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
*                       generation seed which is used to generate two dates in 
*                       the same year, prints those two dates, and then 
*                       calculates and prints the difference in days between 
*                       the two dates.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void setSeed();
void getDate(int*, int*, int*, int*, int*);
int getDayMod(int, int);
void printData(int, int, int, int, int);
int calcDifference(int, int, int, int, int);
int convertDate(int, int, int);

int main()
{
  int year;   // The year of the printed dates
  int month1; // Month of the first date
  int month2; // Month of the second date
  int day1;   // Day of the first date
  int day2;   // Day of the second date

  setSeed();
  
  getDate(&year, &month1, &month2, &day1, &day2);
  printData(year, month1, day1, month2, day2);
  
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
*     Function Description: This function sets the rand seed for the whole program
*
***************************************************************************/
void setSeed()
{
  int seed; // Seed to Set for Program

  printf("\nEnter seed to use for random number generation: ");
  scanf("%d", &seed);
  
  srand(seed);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getDate 
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* year; // The year to store as
*       2. int* month1; // The month to generate
*       3. int* month2; // The month to next generate
*       4. int* day1; // The day to generate
*       5. int* day2; // The next day to generate
*
*     Function Description: This function uses the user input seed and 
*                           generates two different dates both in the same 
*                           randomly generated year
*
***************************************************************************/
void getDate(int* year, int* month1, int* month2, int* day1, int* day2)
{
  *year = 1800 + (rand() % 218);

  *month1 = rand() % 12 + 1; 
  *day1 = rand() % getDayMod(*year, *month1) + 1;

  *month2 = rand() % 12 + 1;
  *day2 = rand() % getDayMod(*year, *month2) + 1;
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getDayMod
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year to determine if leap
*       2. int month; // The month to determine the day
*
*     Function Description: This function accepts a year and month and 
*                           calculates modulus used to calculate the maximum 
*                           amount of days in that month. the dayMod is always 
*                           1 higher than the amount of days in that month
*
***************************************************************************/
int getDayMod(int year, int month)
{
  if((month <= 7 && month % 2) || (month >= 8 && !(month % 2)))
  {
    return(31);
  }
  else if(month == 2) 
  {
    return(28 + ((!(year % 4) && (year % 100)) || !(year % 400)));
  } 
  else
  {
    return(30);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printData
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year from generated date
*       2. int month1; // The first month of the generated date
*       3. int day1; // The first day that was generated
*       4. int month2; // The second month that was generated
*       5. int day2; // The second day that was generated
*
*     Function Description: This function prints the output of the entire 
*                           program. The inputs are the year month and days 
*                           for each of the two months. It also prints the 
*                           difference between the two days but does this 
*                           directly through a call function.
*
***************************************************************************/
void printData(int year, int month1, int day1, int month2, int day2)
{
  int difference; // Difference between the two dates
  difference = calcDifference(year, month1, day1, month2, day2);

  printf("\nFirst Generated Date: %02d/%02d/%d\n", month1, day1, year);
  printf("Second Generated Date: %02d/%02d/%d\n", month2, day2, year);
  printf("Difference between dates: %d day%c.\n\n", difference, 's' * (difference != 1));
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcDifference
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year; // The year
*       2. int month1; // The first month
*       3. int day1; // The first day
*       4. int month2; // The second month
*       5. int day2; // The second day
*
*     Function Description: This function accepts the two dates generated 
*                           in previous functions and calculates the difference 
*                           in days between the two dates.
*
***************************************************************************/
int calcDifference(int year, int month1, int day1, int month2, int day2)
{
  return(abs(convertDate(year, month2, day2) - convertDate(year, month1, day1)));
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: convertDate
*
*     Programmer's Name: Luca von Lintel, Joshua Zhao, Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year;  // The year
*       2. int month; // The month
*       3. int day;   // The day
*
*     Function Description: This function converts a date into the day number of that date.
*
***************************************************************************/
int convertDate(int year, int month, int day)
{

  int date; // The amount of days in a year
  date = 0;

  switch(month)
  {
    case 12:
      date += 30;
    case 11: 
      date += 31;
    case 10:
      date += 30;
    case 9:
      date += 31;
    case 8:
      date += 31;
    case 7:
      date += 30;
    case 6:
      date += 31;
    case 5:
      date += 30;
    case 4:
      date += 31;
    case 3:
      date += 28 + ((!(year % 4) && (year % 100)) || !(year % 400));
    case 2:
      date += 31;
    case 1:
      date += day;
  }
 
  return(date);
}
