/**
 * Write a program to implement SJF scheduling algorithm.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct process
{
  int pid;
  int burstTime;
  int arrivalTime;
  int waitingTime;
  int turnAroundTime;
};

void computeWaitingTime(struct process *processes, int processCount)
{
  int remainingTime[processCount];

  for (int i = 0; i < processCount; i++)
    remainingTime[i] = processes[i].burstTime;

  int check = 0;
  int min = INT_MAX;
  int completionTime, time = 0;
  int complete = 0, shortest = 0;

  while (complete != processCount)
  {
    for (int j = 0; j < processCount; j++)
    {
      if ((processes[j].arrivalTime <= time) &&
          (remainingTime[j] < min) && remainingTime[j] > 0)
      {
        min = remainingTime[j];
        shortest = j;
        check = 1;
      }
    }

    if (check == 0)
    {
      time++;
      continue;
    }

    remainingTime[shortest]--;

    min = remainingTime[shortest];
    if (min == 0)
      min = INT_MAX;

    if (remainingTime[shortest] == 0)
    {
      complete++;
      check = 0;
      completionTime = time + 1;

      processes[shortest].waitingTime =
          completionTime -
          processes[shortest].burstTime -
          processes[shortest].arrivalTime;

      if (processes[shortest].burstTime < 0)
        processes[shortest].burstTime = 0;
    }

    time++;
  }
}

void computeTurnAroundTime(struct process *processes, int processCount)
{
  for (int i = 0; i < processCount; i++)
    processes[i].turnAroundTime =
        processes[i].burstTime +
        processes[i].waitingTime;
}

void printAverageTimes(struct process *processes, int processCount)
{
  float totalWaitingTime = 0.0f;
  float totalTurnAroundTime = 0.0f;
  computeWaitingTime(processes, processCount);
  computeTurnAroundTime(processes, processCount);
  printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
  printf("--------------------------------------------------------");
  printf("-------------------------\n");
  for (int i = 0; i < processCount; i++)
  {
    totalWaitingTime += processes[i].waitingTime;
    totalTurnAroundTime += processes[i].turnAroundTime;
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
           processes[i].pid,
           processes[i].burstTime,
           processes[i].arrivalTime,
           processes[i].waitingTime,
           processes[i].turnAroundTime);
  }
  printf("\nAverage Waiting Time = %.2f",
         totalWaitingTime / processCount);
  printf("\nAverage Turn-Around time = %.2f\n",
         totalTurnAroundTime / processCount);
}

int main(void)
{
  int processCount;

  printf("Enter Number of Processes: ");
  scanf("%i", &processCount);

  struct process processes[processCount];

  for (int i = 0; i < processCount; i++)
  {
    processes[i].pid = i + 1;
    printf("Burst Time for Process %i: ", i + 1);
    scanf("%d", &processes[i].burstTime);
    printf("Arrival Time for Process %i: ", i + 1);
    scanf("%d", &processes[i].arrivalTime);
  }

  printf("\n");

  printAverageTimes(processes, processCount);

  return 0;
}