/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Atif Niyaz aniyaz@purdue.edu
*
*  Homework #: 1
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
*  Program Description: This program asks for information about the structure. This includes the length of the side of the top and bottom of the prism, the total height of the structure, and the cost per cubic meter. It then calculates the volume and the cost of the structure. Finally, the volume and cost are outputted to the user.
*
***************************************************************************/

#include <stdio.h>

int main(void)
{
  
  // Local Declarations (User Input Vars)
  double sideLengthBase;     // Side Length of Prism Base
  double sideLengthTop;      // Side Length of Prism Top
  double height;             // Total Height of Structure
  double costPerCubicMeter;  // Cost of Material Per Cubic Meter

  // Local Declarations (Calaculated Vars)
  double slope;              // Slope of Line Relating Height to the Base Width
  double prismHeight;        // Height of the Prism
  double volume;             // Volume of the Structure
  double materialCost;       // Material Cost of the Structure
  
  // Get User Input
  printf("Enter the side length of the prism base: ");
  scanf("%lf", &sideLengthBase);
  printf("\nEnter the side length of the prism top: ");
  scanf("%lf", &sideLengthTop);
  printf("\nEnter the total height of the structure: ");
  scanf("%lf", &height);
  printf("\nEnter cost of material per cubic meter: ");
  scanf("%lf", &costPerCubicMeter);

  // Executable Statements (Calculate Structure)
  prismHeight = 0.95 * height;
  slope = (sideLengthBase - sideLengthTop) / (prismHeight);
  volume = prismHeight * sideLengthBase * sideLengthBase - slope * prismHeight * prismHeight * sideLengthBase + slope * slope * prismHeight * prismHeight * prismHeight / 3.0 + sideLengthTop * sideLengthTop * (0.05 / 0.95 * prismHeight) / 3.0;
  materialCost = volume * costPerCubicMeter;
  
  // Print Output
  printf("\nThe volume of the structure: %.2f cubic meters", volume);
  printf("\nThe cost of material required: %.2f USD\n", materialCost);

  return 0;
}
