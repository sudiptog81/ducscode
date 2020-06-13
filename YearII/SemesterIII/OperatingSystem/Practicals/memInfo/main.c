/**
 * Write a program to report behaviour of Linux kernel 
 * information on configured memory, amount of free and
 * used memory.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Configured Memory: ");
  fflush(stdout);
  system("awk 'NR == 1 {$1=\"\\b\"; print $0;}' /proc/meminfo");

  printf("Free Memory: ");
  fflush(stdout);
  system("awk 'NR == 2 {$1=\"\\b\"; print $0;}' /proc/meminfo");

  printf("Used Memory: ");
  fflush(stdout);
  system("awk '/MemTotal/ {total=$2; unit=$3;} /MemFree/ {free=$2;} END {printf \"%i %s\\n\", (total-free), unit;}' /proc/meminfo");

  return 0;
}