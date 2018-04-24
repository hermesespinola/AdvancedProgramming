#include <stdio.h>

typedef struct d {
  unsigned day:5;
  unsigned month:4;
  unsigned year;
  unsigned flags:5;
} Date;

#define LEAP_MASK 0b10000
#define PRIME_MASK 0b01000

int main(int argc, char const *argv[]) {
  Date today = { 23, 4, 2018 };
  printf("Size of date %lu\n", sizeof(today));

  printf("Checking if today is 23\n");
  if (today.day ^ 23) {
    printf("No \n");
  } else {
    printf("Yes, today is 23\n");
  }

  today.flags = 0b11010;
  if ((today.flags & (LEAP_MASK | PRIME_MASK)) == (LEAP_MASK | PRIME_MASK)) {
    printf("year is leap\n");
  }
  return 0;
}
