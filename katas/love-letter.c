#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char const *L = argv[1];
  char const *N = argv[2];
  unsigned short *charMap = calloc(sizeof(char), sizeof(unsigned short));
  unsigned short i, charCount;
  char charCode;

  while (*L != '\0') {
    charCode = *L;
    if (charMap[charCode] == 0) {
      charCount += 1;
    }
    charMap[charCode]++;
    L++;
  }

  while (*N != '\0') {
    charCode = *N;
    if (charMap[charCode] > 0) {
      if (--charMap[charCode] ==  0) {
        charCount--;
      }
    }
    if (charCount == 0) {
      printf("mm hum\n");
      return 0;
    }
    N++;
  }

  printf("Na ah\n");
  return 1;
}
