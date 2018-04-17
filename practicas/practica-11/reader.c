#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
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
    printf("%s: ", "Give me an id");
    scanf("%d", &id);
    printf("\n");
    printf("Student[%d] = %s\n", id, pAvanzada[id].firstName);
  }

  munmap(pAvanzada, 10 * sizeof(Student));
  return 0;
}
