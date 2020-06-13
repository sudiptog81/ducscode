/**
 * Write a program to report behaviour of Linux kernel 
 * including kernel version, CPU type and model.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Linux Kernel Version: ");
  fflush(stdout);
  system("awk 'NR == 1 {print $3;}' /proc/version");

  printf("CPU Model: ");
  fflush(stdout);
  system("awk 'NR == 5 {$1=$2=$3=\"\\b\"; print $0;}' /proc/cpuinfo");

  printf("CPU Frequency: ");
  fflush(stdout);
  system("awk 'NR == 8 {$1=$2=$3=\"\\b\"; printf $0; print \" MHz\";}' /proc/cpuinfo");

  printf("CPU Core Count: ");
  fflush(stdout);
  system("grep processor /proc/cpuinfo | wc -l");

  return 0;
}