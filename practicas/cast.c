#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 4;
  float f = 7.5;
  int max = (unsigned int) ~0 >> 1;
  int b = a + f;
  float c = a * f;
  long int d = (long) max * max;
  int array[5];

  *(arreglo + 1) = 250;
  int *p = &a;
  *p = 7;
  ++p = 8;
  ++p = 9;

  printf("p=%p, a=%d, b=%d, d=%ld\n", p, a, b, d);
  printf("f=%f, c=%f\n", f, c);
  return 0;
}
