#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void interruptHandler(int signalCode)
{
  printf("Interrupt Signal Received\n");
  exit(signalCode);
}

int main(void)
{
  int temp;
  signal(SIGINT, interruptHandler);

  while (1)
  {
    scanf("%i", &temp);
  }
}