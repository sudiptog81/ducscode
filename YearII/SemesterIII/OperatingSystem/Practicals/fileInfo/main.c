/**
 * Write a program to print file details including owner
 * access permissions, file access time,where file name
 * is given as argument.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: ./main <file>\n");
    return -1;
  }

  struct stat buf;

  if (stat(argv[1], &buf) < 0)
  {
    fprintf(stderr, "Could not open %s\n", argv[1]);
    return 2;
  }

  printf("File Information\n------------------\n");
  printf("Name: %s\n", argv[1]);
  printf("UID: %0.4d\n", buf.st_uid);
  printf("GID: %0.4d\n", buf.st_gid);
  printf("Regular File: %s\n", S_ISREG(buf.st_mode) ? "Y" : "N");
  printf("Symbolic Link: %s\n", S_ISLNK(buf.st_mode) ? "Y" : "N");
  printf("Directory: %s\n", S_ISDIR(buf.st_mode) ? "Y" : "N");
  printf("Block Device: %s\n", S_ISBLK(buf.st_mode) ? "Y" : "N");
  printf("Character Device: %s\n", S_ISCHR(buf.st_mode) ? "Y" : "N");
  printf("File Mode Bits: %07o\n", buf.st_mode);
  printf("Last Access Time: %lld\n", buf.st_atime);
  printf("Owner Permissions:\n");
  printf("  Read: %s\n", S_IRUSR & buf.st_mode ? "Y" : "N");
  printf("  Write: %s\n", S_IWUSR & buf.st_mode ? "Y" : "N");
  printf("  Execute: %s\n", S_IXUSR & buf.st_mode ? "Y" : "N");
  printf("Group Permissions:\n");
  printf("  Read: %s\n", S_IRGRP & buf.st_mode ? "Y" : "N");
  printf("  Write: %s\n", S_IWGRP & buf.st_mode ? "Y" : "N");
  printf("  Execute: %s\n", S_IXGRP & buf.st_mode ? "Y" : "N");
  printf("Others Permissions:\n");
  printf("  Read: %s\n", S_IROTH & buf.st_mode ? "Y" : "N");
  printf("  Write: %s\n", S_IWOTH & buf.st_mode ? "Y" : "N");
  printf("  Execute: %s\n", S_IXOTH & buf.st_mode ? "Y" : "N");

  return 0;
}