/**
 * Write a program to implement Round Robin scheduling algorithm.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>

struct process
{
  int pid;
  int burstTime;
  int arrivalTime;
  int waitingTime;
  int turnAroundTime;
};

void computeWaitingTime(struct process *processes, int processCount, int quantum)
{
  int remainingTime[processCount];
  for (int i = 0; i < processCount; i++)
    remainingTime[i] = processes[i].burstTime;
  int time = 0;
  while (1)
  {
    int done = 1;
    for (int i = 0; i < processCount; i++)
    {
      if (remainingTime[i] > 0)
      {
        done = 0;
        if (remainingTime[i] > quantum)
        {
          time += quantum;
          remainingTime[i] -= quantum;
        }
        else
        {
          time += remainingTime[i];
          processes[i].waitingTime = time - processes[i].burstTime;
          remainingTime[i] = 0;
        }
      }
    }
    if (done == 1)
      break;
  }
}

void computeTurnAroundTime(struct process *processes, int processCount)
{
  for (int i = 0; i < processCount; i++)
    processes[i].turnAroundTime =
        processes[i].burstTime +
        processes[i].waitingTime -
        processes[i].arrivalTime;
}

void printAverageTimes(struct process *processes, int processCount, int quantum)
{
  float totalWaitingTime = 0.0f;
  float totalTurnAroundTime = 0.0f;
  computeWaitingTime(processes, processCount, quantum);
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
  int processCount, quantum;

  printf("Enter Time Quantum: ");
  scanf("%i", &quantum);

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

  printAverageTimes(processes, processCount, quantum);

  return 0;
}