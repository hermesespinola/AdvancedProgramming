#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int doFullName(char *firstName, char *lastName, char **fullName) {
  int sizeFirstName = strlen(firstName);
  int sizeLastName = strlen(lastName);
  *fullName = (char *) malloc((sizeFirstName + sizeLastName + 1) * sizeof(char));
  strcpy(*fullName, firstName);
  strcpy(*fullName + sizeFirstName, " ");
  strcpy(*fullName + sizeFirstName + 1, lastName);

  return 0;
}

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Insuficient arguments\n");
    return -1;
  }

  char *fullName;
  doFullName((char *)argv[1], (char *)argv[2], &fullName);
  printf("name: %s\n", fullName);
  free(fullName);
  return 0;
}
