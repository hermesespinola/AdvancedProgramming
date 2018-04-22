#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool validUtf8(int *data, int dataSize) {
  unsigned char firstByte = (data[0] & 0xFF);
  unsigned msb = 0x80 & firstByte;
  if (msb == 0 && dataSize == 1) {
    return true;
  } else if (msb == 0) {
    return validUtf8(data + 1, dataSize - 1);
  }

  unsigned expectedBytes = 0, k = 8;
  bool isOne;
  do {
    k--;
    isOne = (((1 << k) & firstByte)) >> k;
    expectedBytes += isOne;
  } while (isOne && k > 0);

  if (k < 3 || k > 5) {
    fprintf(stderr, "Invalid first octet sequence: %d.\n", firstByte);
    return false;
  }
  if (expectedBytes > dataSize) {
    fprintf(stderr, "wrong number of bytes: bytes: %d, nbit: %d\n", expectedBytes, 8 - k);
    return false;
  }

  for (unsigned i = 1; i < expectedBytes; i++) {
    unsigned char lastTwoBits = data[i] & 0xC0;
    if (lastTwoBits >> 6 != 2) {
      fprintf(stderr, "Byte %d: not a continuation byte.\n", i);
      return false;
    }
  }

  if (dataSize > expectedBytes) {
    return validUtf8(data + expectedBytes, dataSize - expectedBytes);
  } else {
    return true;
  }
}

int main(int argc, char const *argv[]) {
  const int dataSize = 1;
  int data[dataSize] = { 145 };
  printf("%i\n", validUtf8(data, dataSize));
  return 0;
}
