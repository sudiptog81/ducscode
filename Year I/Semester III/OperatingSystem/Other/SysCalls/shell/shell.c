#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
  pid_t pid;
  char command[255];
  while (1)
  {
    write(1, "$ ", 2);
    scanf("%s", command);
    if ((pid = fork()) == 0)
    {
      execl(command, "", NULL);
    }
    else if (pid > 0)
    {
      int code = wait(0);
      printf("child exited with code %i\n", code);
    }
    else
    {
      printf("error in fork()");
    }
  }
}