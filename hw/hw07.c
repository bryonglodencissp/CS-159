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

int binarySearch(int array [], int length, int number) 
{
  
  int left = 0;
  int right = length - 1;
  
  int index = 0;

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
