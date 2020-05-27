#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 100

int main(void)
{
  int fd[2];
  pid_t pid;
  char read_msg[BUFFER_SIZE];
  char write_msg[BUFFER_SIZE] = "HELLO WORLD";

  /* create the pipe */
  if (pipe(fd) == -1)
  {
    fprintf(stderr, "Pipe failed");
    return 1;
  }

  /* fork a child process */
  if ((pid = fork()) == 0)
  {
    /* child process */
    close(fd[WRITE_END]);
    unsigned long byteCount = read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("CHILD: %s (read %lu bytes from the pipe)\n", read_msg, byteCount);
  }
  else if (pid > 0)
  {
    /* parent process */
    close(fd[READ_END]);
    write(fd[WRITE_END], write_msg, strlen(write_msg));
    printf("PARENT: %s (wrote %lu bytes to the pipe)\n", write_msg, strlen(write_msg));
  }
  else
  {
    fprintf(stderr, "error in fork()");
    return 1;
  }

  return 0;
}