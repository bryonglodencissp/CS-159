#include <stdio.h>

int numDaysInMonth(int);

int main() {

  int i;
  int num = 0;

  for(i = 1; i < 6; i++) {
    num += numDaysInMonth(i);
  }

  printf("num: %d\n", num);
  return(0);
}

int numDaysInMonth(int month)
{
  int days = 0;

  switch(month % 2 == 0)
    {
    case 1:   days = 31;
      break;
    case 0:   days = month == 2 ? 28 : 30;
    }

  return(days);
}
