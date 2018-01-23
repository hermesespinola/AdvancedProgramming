#include <assert.h>
#include "operations.h"

#define MAX_INT 2147483647

int add(int a, int b) {
  long c = (long) a + b;
  assert(c > -MAX_INT || c <= MAX_INT);
  return (int) c;
}

int substraction(int a, int b) {
  long c = (long) a - b;

  assert(c > -MAX_INT || c <= MAX_INT);
  return (int) c;
}
