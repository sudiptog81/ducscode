/**
 * Write a program to copy a source file into the target file and 
 * display the target file using system calls.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    fprintf(stderr, "Usage: ./main <src> <dest>\n");
    return -1;
  }

  char buf;
  ssize_t bytes;
  int fdSrc, fdDest;
  mode_t wrMode = 0777;

  if ((fdSrc = open(argv[1], O_RDONLY)) < 0)
  {
    fprintf(stderr, "Could not read %s\n", argv[1]);
    return 2;
  }

  if ((fdDest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, wrMode)) < 0)
  {
    fprintf(stderr, "Could not write to %s\n", argv[2]);
    return 2;
  }

  while ((bytes = read(fdSrc, &buf, 1)) > 0)
    write(fdDest, &buf, 1);

  if (bytes < 0)
  {
    fprintf(stderr, "Could not read contents of %s\n", argv[1]);
    return 2;
  }

  if (bytes == 0)
    write(fdDest, "\n", 1);

  printf("Copied contents of %s to %s\n", argv[1], argv[2]);

  close(fdSrc);
  close(fdDest);

  if ((fdDest = open(argv[2], O_RDONLY)) < 0)
  {
    fprintf(stderr, "Could not read %s\n", argv[2]);
    return 2;
  }

  while ((bytes = read(fdSrc, &buf, 1)) > 0)
    printf("%c", buf);

  close(fdDest);

  return 0;
}