#include <stdio.h>

int swap_no(int a, int b) {
  int t;
  t = a;
  a = b;
  b = t;
  return 0;
}

int swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
  return 0;
}

int main(int argc, char const *argv[]) {
  int j = 27, k = 34;
  printf("j=%d, h=%d\n", j, k);
  swap(&j, &k);
  printf("j=%d, h=%d\n", j, k);
  return 0;
}
