/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 2
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Wednesday, 11:30 AM - 1:20 PM, SC 189
*
*  Program Description: Calculate the volume and the type of ellipsoid
*      that is given based on user input. 
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main()
{
  
  // LOCAL DECLARATIONS
  int objXAxis; // X Axis Length of Ellipsoid
  int objYAxis; // Y Axis Length of Ellipsoid
  int objZAxis; // Z Axis Length of Ellipsoid
  double objVolume; // Volume of the Ellipsoid

  int xyDiff; // Difference between X and Y Axis Length
  int yzDiff; // Difference between Y and Z Axis Length
  int xzDiff; // Difference between Z and X Axis Length
  int totalDiff; // Sum of Difference Factors
  char charCode; // Character code for Ellipsoid Shape

  // USER INPUT
  printf("\nEnter the lengths of all three axes: ");
  scanf("%d %d %d", &objXAxis, &objYAxis, &objZAxis);

  // EXECUTABLE STATEMENTS
  objVolume = 4.0 * PI * objXAxis * objYAxis * objZAxis / 3.0;
  
  xyDiff = ceil(fabs(objXAxis - objYAxis)/(objXAxis * objYAxis + 1));
  yzDiff = ceil(fabs(objYAxis - objZAxis)/(objYAxis * objZAxis + 1));
  xzDiff = ceil(fabs(objZAxis - objXAxis)/(objZAxis * objXAxis + 1));
  totalDiff = xyDiff + yzDiff + xzDiff;

  charCode = (int) ((5.0 / 3) * pow(totalDiff, 2) - (28 / 3.0) * totalDiff + 80);

  // OUTPUT
  printf("\nObject volume: %.2lf\n", objVolume);
  printf("Object Shape: %c\n\n", charCode);
  
  return(0);
} // MAIN
