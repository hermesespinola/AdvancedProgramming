#include <stdio.h>
#include "operations.h"
#include "messages.h"

void testAddition(void);
void testSubstraction(void);
void printTestMessage(int, char*, char*);

void printTestMessage(int condition, char *messagePass, char *messageFailed) {
  if (condition) {
    printf("%s\n", messagePass);
  } else {
    printf("%s\n", messageFailed);
  }
}

void testAddition(void) {
  int a = 5;
  int b = 7;

  int result = add(a, b);
  int expected = a + b;

  if (result == expected) {
    printf("Add test passed\n");
  } else {
    fprintf(stderr, "Add test failed\n");
  }
}

void testSubstraction(void) {
  int a = 5;
  int b = 7;

  int result = substraction(a, b);
  int expected = a - b;

  printTestMessage(a == b, "Substraction test passed", "Substraction test failed");
}

int main(int argc, char const *argv[]) {
  testAddition();
  testSubstraction();
}
