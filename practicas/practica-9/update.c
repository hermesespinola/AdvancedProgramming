#include <stdio.h>
#include <string.h>

typedef struct {
  char firstName[20];
  char lastName[20];
  short Id;
  char semester[3];
  char free;
} Student;

int main(int argc, char *argv[]) {
  char *searchName = argv[1];
  char *update = argv[2];
  char *dbName = "student.dat";
  Student myStudent;

  FILE *data = fopen(dbName, "r+b");
  while (1) {
    fread(&myStudent, sizeof(Student), 1, data);
    if (feof(data)) break;
    if (!strcmp(myStudent.firstName, searchName)) {
      strcpy(myStudent.firstName, update);
      fseek(data, -1 * sizeof(Student), SEEK_CUR);
      fwrite(&myStudent, sizeof(Student), 1, data);
      break;
    }
  }

  return 0;
}
