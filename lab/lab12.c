
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Atif Niyaz aniyaz@purdue.edu
*	 2. Canyu Yang yang1083@purdue.edu
*	 3. Ittichot Suwanmungkool isuwanmu@purdue.edu
*
*  Lab #: 12
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M. - 1:20 P.M., SC 189
*
*  Program Description: This program keeps track of students that are
*                       exiting and returning. Students are tracked based
*                       on their ID number which is stored in the program.
*
***************************************************************************/

#include <stdio.h>

#define MAX_CLASS 30

int getExiting(int []);
int getReturning(int []);

void checkAttendance(int [], int [], int, int);
int find(int [], int [], int, int, int []);

void printList(int [], int);
void insertionSort(int [], int);

int main()
{

  int exiting [MAX_CLASS] = {0}; // The array of exiting students
  int returning [MAX_CLASS] = {0}; // The array of returning students

  int exitingLength = getExiting(exiting); // The length of the array of exiting students
  int returningLength = getReturning(returning); // The length of the array of returning students

  checkAttendance(exiting, returning, exitingLength, returningLength);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getExiting
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array []; // The array to populate
*
*     Function Description: Populates the array with exiting students
*
***************************************************************************/

int getExiting(int array [])
{

  int i = -1; // Iterator
  printf("\nEnter set of exiting students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  if(!((i + 1) < MAX_CLASS))
  {
    i++;
  }
  
  return(i);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getReturning
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array []; // The array to populate
*
*     Function Description: Populates the array with returning students
*
***************************************************************************/

int getReturning(int array [])
{

  int i = -1; // Iterator
  printf("Enter set of returning students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  if(!((i + 1) < MAX_CLASS) && array[MAX_CLASS - 1] != -1)
  {
    i++;
  }
  
  return(i);
}


/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkAttendance
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int exiting []; // The array of exiting students
*       2. int returning []; // The array of returning students
*       3. int exitLen; // The length of the exiting students array
*       4. int returnLen; // The length of the returning students array
*
*     Function Description: Check attendance of the students and report 
*                           the status.
*
***************************************************************************/

void checkAttendance(int exiting [], int returning [], int exitLen, int returnLen)
{

  int valuesExit [MAX_CLASS + 1] = {0}; // Array of those who exited but did not return
  int valuesReturn [MAX_CLASS + 1] = {0}; // Array of those who returned but did not exit
  int countExit = find(exiting, returning, exitLen, returnLen, valuesExit); // Length of exited but did not return
  int countReturn = find(returning, exiting, returnLen, exitLen, valuesReturn); // Lenght of returned but did not exit

  if(countExit == 0 && countReturn == 0)
  {
    printf("\nAll exiting students returned.\n\n");
  }
  else
  {
    if(countExit != 0)
    {
      printf("\nStudents returning but not exiting:");
      printList(valuesExit, countExit);
      printf("\n\n");
    }

    if(countReturn != 0)
    {
      if(countExit == 0) 
      {
	printf("\n");
      }

      printf("Students exiting but not returning:");
      printList(valuesReturn, countReturn);
      printf("\n\n");
    }
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: find
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int exiting []; // The array of exiting students
*       2. int returning []; // The array of returning students
*       3. int exitLen; // The length of exiting students
*       4. int returnLen; // The length of returning students
*       5. int values[]; // The array of students that were found
*
*     Function Description: Finds students and puts them into the values[]
*
***************************************************************************/

int find(int exiting [], int returning [], int exitLen, int returnLen, int values [])
{

  int i; // For-loop iterator
  int j; // For-loop iterator
  int cnt = 0; // Count of values not found
  
  for(i = 0; i < exitLen; i++)
  {
    for(j = 0; j < returnLen; j++)
    {
      if(exiting[i] == returning[j])
      {
	j = 99;
      }
    }

    if(j != 100)
    {
      values[cnt] = exiting[i];
      cnt++;
    }
  }

  values[cnt] = -1;
  return(cnt);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: printList
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array[]; // The array of data
*       2. int len; // The length of the array
*
*     Function Description: Prints the list of elements in an array
*
***************************************************************************/

void printList(int array [], int len)
{
  int i; // For-loop iterator
  insertionSort(array, len);

  for(i = 0; i < len; i++)
  {
    printf(" %d", array[i]);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: insertionSort
*
*     Programmer's Name: Atif Niyaz, Canyu Yang, Ittichot Suwanmungkool
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array []; // The array to sort
*       2. int len; // The length of said array
*
*     Function Description: Use insertion sort to sort the array
*
***************************************************************************/

void insertionSort(int array [], int len) 
{

  int min; // Index of minimum value
  int temp; // Temp value used for value swap

  int i; // For-loop iterator
  int j; // For-loop iterator

  for(i = 0; i < len - 1; i++)
  {
    min = i;
    for(j = i; j < len; j++)
    {
      if(array[min] > array[j])
      {
	min = j;
      }	
    }

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

