#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  int pid;
  pid = fork();
  if (pid == 0) {
    pid = fork();
    if (pid == 0) {
      printf("I am the daemon!\n");
      fclose(stdin);
      fclose(stdout);
      fclose(stderr);
      umask(0);
      chdir("/tmp");
      while (1) {

      }
    }

    wait(NULL);
  }
  return 0;
}
