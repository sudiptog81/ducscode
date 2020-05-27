#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
  pid_t pid;
  while (1)
  {
    write(1, "$ ", 2);
    if ((pid = fork()) == 0)
    {
      exec(argv[0], argv[1]);
    }
    else if (pid > 0)
    {
      wait(0);
    }
    else
    {
      printf("error in fork()");
    }
  }
}