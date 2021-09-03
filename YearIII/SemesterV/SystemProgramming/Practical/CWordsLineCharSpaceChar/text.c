#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop()
{
  int i, j = 5; // okay
  for (int i = 0; i < j; i++)
  {
    printf("%d. Hi\n", (i + 1));
  }
}

int main()
{
  double a = -3.14;
  char at = '@', tab = '\t';

  loop();

  return 0;
}

// sudipto
