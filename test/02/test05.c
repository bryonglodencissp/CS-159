#include <stdio.h>

int measureNumber(int);
int findNum(int, int);

int main() {

  int n;
  n = findNum(1333, 0);
  printf("First %d\n", n);

  n = findNum(1333, 100);
  printf("Second %d\n", n);

  return(0);
}

int findNum(int n, int opt) {

  int measure;

  do {

    measure = measureNumber(n);
    n++;
  }while(measure != opt);

  return(n - 1);
}

int measureNumber(int n) {

  int dig1;
  int dig2;
  int dig3;

  int ct = 0;

  while(n >= 10)
    {
      dig1 = n % 10;
      dig2 = (n / 10) % 10;
      dig3 = (n / 100) % 10;

      if(dig1 == dig2 && dig2 == dig3) {

	ct += 100;
	n /= 10;
      } else if(dig1 == dig2)
	{
	  ct += 1;
	}

      n /= 10;
    }
  return(ct);
}
