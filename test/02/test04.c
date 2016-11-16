#include <stdio.h>

void elevenToNineteen(int);
void print1Dig(int);

int main() {

  int i;

  for(i = 10; i < 20; i+= 3) {
    elevenToNineteen(i);
    printf("\n");
  }

  return 0;

}

void elevenToNineteen(int num)
{

  if(num == 11)
    printf("eleven");
  else if(num == 12)
    printf("twelve");
  else {
    switch(num - 10) {
    case 3:
      printf("thir");
      break;
    case 5:
      printf("fif");
      break;
    case 8:
      printf("eigh");
    case 4:
    case 6:
    case 7:
    case 9:
      print1Dig(num - 10);
    }

    printf("teen");
   
  }
}

void print1Dig(int num) {
  switch(num)
    {
    case 4:
      printf("four");
      break;
    case 6:
      printf("six");
      break;
    case 7:
      printf("seven");
      break;
    case 9:
      printf("nine");
      break;
    }
}
