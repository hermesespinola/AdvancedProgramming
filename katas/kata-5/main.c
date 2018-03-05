#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void infographic(HashInt *table, FILE *input) {
  char string[256];

  while (!feof(input)) {
    if (fscanf(input, "%s", string) != 1) {
      break;
    }
    int len = strlen(string);
    if (string[len - 1] == '.') {
      string[--len] = '\0';
    }

    for(int i = 0; string[i]; i++){
      string[i] = tolower(string[i]);
    }

    int *val = NULL;
    if ((val = hashGet(table, string)) == NULL) {
      hashInsert(table, string, 1);
    } else {
      hashInsert(table, string, *val + 1);
    }
  }
}

int main(int argc, char const *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  int sizeHash = 100;
  HashInt table;
  hashInit(&table, sizeHash);
  infographic(&table, fp);
  printHash(&table);
  return 0;
}
