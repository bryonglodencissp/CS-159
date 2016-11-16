#include <stdio.h>

int main()
{

  int x = 13;
  int y = 29;
  int z = 16;

  if(y % x > y % z)
  {
    z++;
  }
  else if(y / z > y / x)
  {
    x++;
  }
  else if(y / ++x / (--z - 1))
  {
    y++;
  }

  printf("x: %d\n", x);
  printf("y: %d\n", y);
  printf("z: %d\n", z);
}
