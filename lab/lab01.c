/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. Atif Niyaz aniyaz@purdue.edu
*	 2. Kendrick Wang wang2659@purdue.edu
*	 3. Johnathan Skene jskene@purdue.edu 
*
*  Lab #: 1
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
*  Program Description: This program will calculate the circumfrence,
*                       volume, and surface area from user input of 
*                       radius and display the calculated values to 
*                       the user.
*
***************************************************************************/

#include <stdio.h>
#define PI 3.1416

int main(void)
{
  // Local Declarations
  float radius; // Radius of Sphere
  float circ; // Circumfrence of Sphere
  float surfaceArea; // Surface Area of Sphere
  float volume; // Volume of Sphere

  // Ask for User Input
  printf("\nPlease enter the value of the radius: ");
  scanf("%f", &radius);

  // Executable Statements
  circ  = 2 * PI * radius;
  surfaceArea = 4 * PI * radius * radius;
  volume = surfaceArea * radius / 3;

  // Output of Calculated Values
  printf("\nThe Radius is:        %10.3f", radius);
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nThe Circumference is: %10.3f", circ);
  printf("\nThe Volume is:        %10.3f", volume);
  printf("\nThe Surface Area is:  %10.3f", surfaceArea);
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
}
