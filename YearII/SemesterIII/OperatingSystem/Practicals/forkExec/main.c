/**
 * Write a program (using fork() and/or exec() commands)
 * where parent and child execute: 
 *  (a) same program, same code
 *  (b) same program, different code
 *  (c) before terminating, the parent waits for the child
 *      to finish its task.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void sameProgSameCode()
{
  pid_t pidShell = getppid(), pidFork;

  printf("Shell PID: %lld\n", pidShell);

  if ((pidFork = fork()) < 0)
    fprintf(stderr, "Error in fork()");
  else
    printf("Process ID: %lld\n", getpid());

  if (pidFork == 0)
    exit(0);

  return;
}

void sameProgDiffCode()
{
  pid_t pidShell = getppid(), pidFork;

  printf("Shell PID: %lld\n", pidShell);

  if ((pidFork = fork()) < 0)
  {
    fprintf(stderr, "Error in fork()\n");
  }
  else if (pidFork > 0)
  {
    printf("PARENT: Forked Child\n");
  }
  else
  {
    printf("CHILD: Parent Process ID: %lld\n", getppid());
    printf("CHILD: Process ID: %lld\n", getpid());
    exit(0);
  }

  return;
}

void waitForChild()
{
  pid_t pidFork, pidShell = getppid();

  printf("Shell PID: %lld\n", pidShell);

  if ((pidFork = fork()) < 0)
  {
    fprintf(stderr, "Error in fork()\n");
  }
  else if (pidFork > 0)
  {
    wait(NULL);
    printf("PARENT: Child Exited\n");
  }
  else
  {
    printf("CHILD: Parent Process ID: %lld\n", getppid());
    printf("CHILD: Process ID: %lld\n", getpid());
    exit(0);
  }

  return;
}

int main(void)
{
  int choice;

  do
  {
    printf("=== MENU ================\n");
    printf("  (1) same program, same code\n");
    printf("  (2) same program, different code\n");
    printf("  (3) the parent waits for the child\n");
    printf("  (0) exit\n");
    printf("\nEnter Choice: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
      sameProgSameCode();
      while (getchar() != '\n')
        ;
      getchar();
      system("clear");
      break;
    case 2:
      sameProgDiffCode();
      while (getchar() != '\n')
        ;
      getchar();
      system("clear");
      break;
    case 3:
      waitForChild();
      while (getchar() != '\n')
        ;
      getchar();
      system("clear");
      break;
    default:
      break;
    }
  } while (choice != 0);

  return 0;
}