#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "student.h"

int main(int argc, char const *argv[]) {
  char *fileName = "student.dat";
  int id;
  char name[20];
  int fd = open(fileName, O_RDWR);
  Student *pAvanzada = (Student *) mmap(
    NULL,
    10 * sizeof(Student),
    PROT_READ | PROT_WRITE,
    MAP_FILE | MAP_SHARED,
    fd,
    0);
  close(fd);

  for (size_t i = 0; i < 4; i++) {
    printf("%s\n", "Give me an id and a name");
    scanf("%d %s", &id, name);
    strcpy(pAvanzada[id].firstName, name);
  }

  munmap(pAvanzada, 10 * sizeof(Student));
  return 0;
}
