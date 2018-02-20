#include <stdlib.h>
#include <stdio.h>

typedef struct s {
  int id;
  char *name;
} Student;

void sortById(Student *, int numel);
void sortByName(Student *, int numel);
