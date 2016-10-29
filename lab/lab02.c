/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Johnathan Skene jskene@purdue.edu
*	 2. Kendrick Wang wang2659@purdue.edu
*	 3. Atif Niyaz aniyaz@purdue.edu
*	 
*  Lab #: 02
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday 11:30AM - 1:20PM, SC 189
*
*  Program Description: Calculate the volume of a washer and torus with user
*  input radius of the washer and side length of the washer cross section, 
*  then compare the volumes of the two objects and display results to the 
*  desired user input for precision.
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

// GLOBAL DECLARATIONS
#define PI 3.1416

int main(void) 
{
  
  // LOCAL DECLARATIONS
  double washerRadius; // Washer Radius
  double washerSideLen; // Side Length of Washer Cross Section
  double washerVolume; // Volume of the Washer
  double torusVolume; // Volume of the Torus
  int precision; // Precision for Answer

  // GET USER INPUT
  printf("\nEnter the smaller radius of the washer: ");
  scanf("%lf", &washerRadius);
 
  printf("Enter the side length of washer cross section: ");
  scanf("%lf", &washerSideLen);
  
  printf("Enter the desired precision: ");
  scanf("%d", &precision);

  // EXECUTABLE STATEMENTS
  washerVolume = (pow(washerRadius + washerSideLen, 2) * PI - pow(washerRadius, 2) * PI) * washerSideLen;
  torusVolume = 2 * pow(PI, 2) * pow(washerSideLen * 0.5, 2) * (washerRadius + washerSideLen * 0.5); 
 
  // PRINT OUTPUT
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Volume of washer:%25.*f cubic meters\n", precision, washerVolume);
  printf("Volume of torus :%25.*f cubic meters\n", precision, torusVolume);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Volume lost: %-15.*f cubic meters\n", precision, (washerVolume - torusVolume));
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

  return(0);
} // MAIN
