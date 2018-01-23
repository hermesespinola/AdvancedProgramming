#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "messages.h"

#define MAX_STRING_LENGTH 100
#define LANG "ES"

typedef struct {
  char *operationName;
  int (* operation) (int, int);
} Operation;

int main() {
  char operation[MAX_STRING_LENGTH];
  int operatorOne, operatorTwo;
  char **messages;

  if (!strcmp(LANG, "eng")) {
    messages = messages_ENG;
  } else if (!strcmp(LANG, "es")) {
    messages = messages_ES;
  }

  printf("%s", messages[0]);
  scanf("%s", operation);
  scanf("%d %d", &operatorOne, &operatorTwo);

  int result;
  if (!strcmp(operation, "add")) {
    result = add(operatorOne, operatorTwo);
  } else if (!strcmp(operation, "substraction")) {
    result = substraction(operatorOne, operatorTwo);
  } else {
    fprintf(stderr, "%s\n", messages[1]);
    return -1;
  }

  printf("%s: %d\n", messages[2], add(operatorOne, operatorTwo));
  return 0;
}
