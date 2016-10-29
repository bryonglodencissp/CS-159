/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Atif Niyaz aniyaz@purdue.edu
*	 2. Kendrick Wang wang2659@purdue.edu
*	 3. Johnathan Skene jskene@purdue.edu
*
*  Lab #: 4
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday, 11:30 AM - 1:30 PM, SC 189
*
*  Program Description: calculate the volume, surface area, and determine
*        the shape of an ellipsoid using user-defined functions
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI M_PI

int getAxisLength(int);
double calcVolume(int, int, int);
double calcArea(int, int, int);
int compareValues(int, int);
char determineShape(int, int, int);
void displayResults(char, double, double);

int main()
{
  
  // LOCAL DECLARATIONS
  int objXAxis; // X Axis Length of Ellipsoid
  int objYAxis; // Y Axis Length of Ellipsoid
  int objZAxis; // Z Axis Length of Ellipsoid

  double objVolume; // Volume of the Ellipsoid
  double objSA; // Surface Area of the Ellipsoid

  char charCode; // Character code for Ellipsoid Shape

  // Add New Line Before Program
  printf("\n");

  // GET INPUT
  objXAxis = getAxisLength(1);
  objYAxis = getAxisLength(2);
  objZAxis = getAxisLength(3);
  
  objVolume = calcVolume(objXAxis, objYAxis, objZAxis);
  objSA = calcArea(objXAxis, objYAxis, objZAxis);

  charCode = determineShape(compareValues(objXAxis, objYAxis), compareValues(objYAxis, objZAxis), compareValues(objZAxis, objXAxis));

  displayResults(charCode, objVolume, objSA);
  
  return(0);
} // MAIN

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getAxisLength
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int count // The axis number to retrieve
*
*     Function Description: Scan for the input of the axis length and return it as an int
*
***************************************************************************/
int getAxisLength(int count)
{
  printf("Enter length of axis #%d: ", count);
  scanf("%d", &count);
  return(count);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcVolume
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: double
*
*     Parameters (list data type, name, and comment one per line):
*       1. int xLen // Length of X axis 
*       2. int yLen // Length of Y axis
*       3. int zLen // Length of Z axis
*
*     Function Description: calculate the volume of an ellipsoid given
*      the x, y and z axes values
*
***************************************************************************/
double calcVolume(int xLen, int yLen, int zLen)
{
  return(4.0 * PI * xLen * yLen * zLen / 3.0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcArea
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: double
*
*     Parameters (list data type, name, and comment one per line):
*       1. int xLen // Length of X axis
*       2. int yLen // Length of Y axis
*       3. int zLen // Length of Z axis
*
*     Function Description: Calculate the surface area of an ellipsoid with
*         axes x, y and z
*
***************************************************************************/
double calcArea(int xLen, int yLen, int zLen)
{
  return(4.0 * PI * pow((pow(xLen, 1.6) * pow(yLen, 1.6) + pow(yLen, 1.6) * pow(zLen, 1.6) + pow(zLen, 1.6) * pow(xLen, 1.6)) / 3.0, 1 / 1.6)); 
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: compareValues
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int compA // First item to compare with
*       2. int compB // Second item to compare
*
*     Function Description: Compare two values and return a 0 if the are the same 
*         or a 1 if they are different
*
***************************************************************************/
int compareValues(int compA, int compB)
{
  return((abs(compA - compB) + 2) % (abs(compA - compB) + 1));
}
 
/***************************************************************************
*
*     Function Information
*
*     Name of Function: determineShape
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: char
*
*     Parameters (list data type, name, and comment one per line):
*       1. int diffXY // Difference between X and Y
*       2. int diffYZ // Difference between Y and Z
*       3. int diffZX // Difference between Z and X
*
*     Function Description: Determine the shape of the ellipsoid
*
***************************************************************************/
char determineShape(int diffXY, int diffYZ, int diffZX)
{
  int totalDiff; // Total of the Differences
  totalDiff = diffXY + diffYZ + diffZX;

  return((int) ((5.0 / 3) * pow(totalDiff, 2) - (28 / 3.0) * totalDiff + 80));
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayResults
*
*     Programmer's Name: Atif Niyaz, Johnathan Skene, Kendrick Wang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. char code // The ellipsoid code
*       2. double vol // the volume of the ellipsoid
*       3. double sa // the surface area of the ellipsoid
*
*     Function Description: Display the Ellipsoid Code, Volume and SA
*
***************************************************************************/
void displayResults(char code, double vol, double sa)
{
  printf("\nObject volume: %.2lf\nObject surface area: %.2lf\nObject Shape: %c\n\n", vol, sa, code);
}
