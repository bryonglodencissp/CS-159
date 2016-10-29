/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Atif Niyaz aniyaz@purdue.edu
*	 2. Kendrick Wang wang2659@purdue.edu
*	 3. Johnathan Skene jskene@purdue.edu 
*
*  Lab #: 3
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday, 11:30 AM - 1:20 PM, SC 189
*
*  Program Description: Calculate the volume, surface area, and cost of
*      building and painting a torus. In addition, determine the type of
*      torus that is being calculated.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

#define COST_PROD_CB_METER 75.25
#define COST_PROD_SQ_METER 13.65

int main()
{
  
  // LOCAL DECLARATIONS
  int majorRadius; // Major Radius of Torus
  int minorRadius; // Minor Radius of Torus
  
  int majorKey; // Major Key
  int minorKey; // Minor Key

  char firstKeyCode; // First Letter of Code
  char secondKeyCode; // Second Letter of Code
  
  double volume; // Volume of Torus
  double surfaceArea; // Surface Area of Torus

  // ASK FOR INPUT
  printf("\nPlease input major radius (meters): ");
  scanf("%d", &majorRadius);
  printf("Please input minor radius (meters): ");
  scanf("%d", &minorRadius);
  
  // EXECUTABLE STATEMENTS
  majorKey = ceil(((majorRadius - minorRadius) + fabs(majorRadius - minorRadius)) / (majorRadius));
  minorKey = ceil(((minorRadius - majorRadius) + fabs(minorRadius - majorRadius)) / (minorRadius));
  
  firstKeyCode = majorKey * 10 + minorKey * 11 + 72;
  secondKeyCode = majorKey * -5 + minorKey * 2 + 110;
  
  volume = 2 * M_PI * M_PI * majorRadius * minorRadius * minorRadius;
  surfaceArea = 4 * M_PI * M_PI * majorRadius * minorRadius;
 
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\nManufacturing Code : %11c%c", firstKeyCode, secondKeyCode);
  printf("\nSurface Area       : %12.2lf", surfaceArea);
  printf("\nVolume             : %12.2lf", volume);
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Cost of building torus ($): %12.2lf\n", volume * COST_PROD_CB_METER);
  printf("Cost of painting torus ($): %12.2lf\n", surfaceArea * COST_PROD_SQ_METER);
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
  
  return(0);
}
