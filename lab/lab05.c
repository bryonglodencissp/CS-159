/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. login1@purdue.edu
*	 2. login2@purdue.edu
*	 3. login3@purdue.edu (delete line if no third partner)
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section:
*
*  Program Description:
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

#define G 9.80665
#define PI M_PI

void getVelocity(int*);
void getAngle(int*);
void getAvgSpeed(double*);
double getTime(int, int);
double getFlightRange(int, int);
double getMaximumHeight(int, int);
double getRetrievalTime(int, int, double);
void printResults(double, double, double, double);
void printConvertTime(double);

int main() 
{ 
  int velocity;
  int angle;
  double avgSpeed;
  double time;
  double range;
  double height;
  double retrieveTime;

  printf("\n");

  getVelocity(&velocity);
  getAngle(&angle);
  getAvgSpeed(&avgSpeed);
  
  time = getTime(velocity, angle);
  range = getFlightRange(velocity, angle);
  height = getMaximumHeight(velocity, angle);
  retrieveTime = getRetrievalTime(velocity, angle, avgSpeed);

  printResults(time, range, height, retrieveTime);
  return(0);
}

void getVelocity(int* velocity) {
  printf("Enter launch velocity (m/s): ");
  scanf("%d", velocity);
}

void getAngle(int* angle) 
{
  printf("Enter launch angle (degrees): ");
  scanf("%d", angle);
}

void getAvgSpeed(double* speed)
{
  printf("Enter average speed of rover (km/h): ");
  scanf("%lf", speed);
}

double getTime(int velocity, int angle) 
{
  return(velocity * sin(angle / 180.0 * PI) / (0.5 * G));
}

double getFlightRange(int velocity, int angle)
{
  return cos(angle / 180.0 * PI) * velocity * getTime(velocity, angle); 
}

double getMaximumHeight(int velocity, int angle) 
{
  return velocity * sin(angle / 180.0 * PI) * getTime(velocity, angle) / 2 - 0.5 * G * pow(getTime(velocity, angle) / 2, 2);
}

double getRetrievalTime(int velocity, int angle, double avgSpeed) 
{
  return getFlightRange(velocity, angle) / (avgSpeed * 1000.0 / pow(60, 2));
}

void printResults(double time, double range, double height, double retTime)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Flight Time   : ");
  printConvertTime(time);
  printf("\n\nFlight Range  :%12.3lf meters\n", range);
  printf("Maximum Height:%12.3lf meters", height); 
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Retrieval Time: ");
  printConvertTime(retTime);
  printf("\n\n");
}

void printConvertTime(double time) 
{
  int hrs; // Hours to Convert To
  int min; // Minutes to Convert To
  double sec; // Seconds to Convert To

  hrs = ((int) time) / 3600;
  min = (((int) time) % 3600) / 60;
  sec = time - hrs * 3600 -  min * 60;
  
  printf("%d (hrs) %02d (minutes) %.2lf (seconds)", hrs, min, sec);
}
