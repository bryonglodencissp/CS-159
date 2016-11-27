
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 07
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
*  Program Description: This program determines how many points that a car
*                       with a certain mileage cannot go to consecutively.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_MILE_MARKERS 50

int getFuelRange();
int getStartingMileMarker();
int getMileMarkerPositions(int []);

void insertionSort(int [], int);
int binarySearch(int [], int, int);
void findAllPoints(int [], int, int, int);

int main() 
{

  int fuelRange = getFuelRange(); // Fuel range
  int startingMarker = getStartingMileMarker(); // Starting mile markers
  int mileMarkers [MAX_MILE_MARKERS] = {}; // Array of mile markers
  int mileMarkersLength = getMileMarkerPositions(mileMarkers); // Length of mile marker array
  int startingMarkerIndex; // Index of starting marker

  insertionSort(mileMarkers, mileMarkersLength);
  startingMarkerIndex = binarySearch(mileMarkers, mileMarkersLength, startingMarker);
  findAllPoints(mileMarkers, mileMarkersLength, startingMarkerIndex, fuelRange);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getFuelRange()
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Function Description: Gets and validates the fuel range from STDIN
*
***************************************************************************/

int getFuelRange() 
{

  int fuelRange; // The fuel range

  printf("\n");

  do 
  {

    printf("Enter maximum fuel range: ");
    scanf("%d", &fuelRange);

    if(fuelRange <= 0) 
    {
      printf("\nError! Positive values only!!\n\n");
    }
  } while(fuelRange <= 0);

  return(fuelRange);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getStartingMileMarker
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Function Description: Gets and validates the value of the starting 
*                           milemarker from STDIN
*
***************************************************************************/

int getStartingMileMarker() 
{

  int mileMarker; // The starting mile marker
  
  do 
  {

    printf("Enter starting mile marker location: ");
    scanf("%d", &mileMarker);

    if(mileMarker < 0) 
    {
      printf("\nError! Non-negative values only!!\n\n");
    }
  } while(mileMarker < 0);

  return(mileMarker);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getMileMarkerPositions
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int mileMarkers []; // The array of mile markers
*
*     Function Description: Gets the data of the mile markers from STDIN
*                           Returns the length of the array
*
***************************************************************************/

int getMileMarkerPositions(int mileMarkers []) 
{

  int len = 0; // Length of array
  
  printf("Enter mile marker positions: ");

  while(len <= MAX_MILE_MARKERS && (len > 0 ? mileMarkers[len - 1] != -1 : len <= 0))
  {
    scanf("%d", &mileMarkers[len]);
    len++;
  }

  return(len - 1);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: insertionSort
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array []; // The array to sort
*       2. int length; // The actual length of the array
*
*     Function Description: Insertion sorts the array so it is sorted
*
***************************************************************************/

void insertionSort(int array [], int length) 
{

  int min; // Index of minimum value
  int temp; // Temp value used for value swap
  
  int i; // For-loop iterator
  int j; // For-loop iterator

  for(i = 0; i < length - 1; i++)
  {
    min = i;

    for(j = i; j < length; j++) 
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

/***************************************************************************
*
*     Function Information
*
*     Name of Function: binarySearch
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array []; // The array to search through (must be sorted)
*       2. int length; // The actual length of the array
*       3. int number; // Desired number to look for
*
*     Function Description: Does a binary search to find the desired number
*
***************************************************************************/

int binarySearch(int array [], int length, int number) 
{
  
  int left = 0; // Left bounds of array to search
  int right = length - 1; // Rights bound of array to search
  
  int index = 0; // Actual index of number

  while(array[index] != number) 
  {
    
    index = (left + right) / 2;
    
    if(array[index] > number)
    {
      right = index - 1;
    }
    
    if(array[index] < number)
    {
      left = index + 1;
    }
  }

  return(index);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: findAllPoints
*
*     Programmer's Name: Atif Niyaz
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int array[]; // The array of milemarkers
*       2. int length; // The length of the array of milemarkers
*       3. int startingIndex; // The index of starting milemarker
*       4. int mileage; // The mileage of the vehicle
*
*     Function Description: Find all points that can be reached. Then take
*                           the length and subtract by points to find 
*                           points that were not reached.
*
***************************************************************************/

void findAllPoints(int array[], int length, int startingIndex, int mileage)
{
  
  int points = 1; // Number of points that can be reached.
  int i; // For-loop iterator

  printf("\n");

  for(i = startingIndex - 1; i >= 0; i--)
  {
    if(abs(array[i + 1] - array[i]) > mileage) 
    {
      i = -1;
    } 
    else 
    {
      points++;
    }
  }

  for(i = startingIndex + 1; i < length; i++)
  {
    if(abs(array[i - 1] - array[i]) > mileage) 
    {
      i = length;
    } 
    else 
    {
      points++;
    }
  }

  points = length - points;

  if(points == 0) 
  {
    printf("All points can be reached.\n\n");
  }
  else if(points == 1)
  {
    printf("Only a single point cannot be reached.\n\n");
  }
  else
  {
    printf("A total of %d points cannot be reached.\n\n", points);
  }
}
