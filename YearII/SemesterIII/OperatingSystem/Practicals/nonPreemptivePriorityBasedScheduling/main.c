/**
 * Write a program to implement non-preemptive priority
 * based scheduling algorithm.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>

struct process
{
  int pid;
  int priority;
  int burstTime;
  int arrivalTime;
  int waitingTime;
  int turnAroundTime;
};

int comparisonDesc(const void *a, const void *b)
{
  return ((struct process *)a)->priority < ((struct process *)b)->priority;
}

int comparisonAsc(const void *a, const void *b)
{
  return ((struct process *)a)->pid > ((struct process *)b)->pid;
}

void computeWaitingTime(struct process *processes, int processCount)
{
  qsort(processes, processCount, sizeof(struct process), comparisonDesc);
  processes[0].waitingTime = 0;
  for (int i = 0; i < processCount - 1; i++)
    processes[i + 1].waitingTime =
        processes[i].burstTime +
        processes[i].waitingTime;
}

void computeTurnAroundTime(struct process *processes, int processCount)
{
  for (int i = 0; i < processCount; i++)
    processes[i].turnAroundTime =
        processes[i].burstTime +
        processes[i].waitingTime;
  qsort(processes, processCount, sizeof(struct process), comparisonAsc);
}

void printAverageTimes(struct process *processes, int processCount)
{
  float totalWaitingTime = 0.0f;
  float totalTurnAroundTime = 0.0f;
  computeWaitingTime(processes, processCount);
  computeTurnAroundTime(processes, processCount);
  printf("Process ID\tPriority\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
  printf("--------------------------------------------------------");
  printf("-----------------------------------------\n");
  for (int i = 0; i < processCount; i++)
  {
    totalWaitingTime += processes[i].waitingTime;
    totalTurnAroundTime += processes[i].turnAroundTime;
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
           processes[i].pid,
           processes[i].priority,
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
    printf("Priority for Process %i: ", i + 1);
    scanf("%d", &processes[i].priority);
  }

  printf("\n");

  printAverageTimes(processes, processCount);

  return 0;
}