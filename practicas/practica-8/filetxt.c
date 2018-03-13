#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printDebug(...) do { \
  char *isDebug = getenv("DEBUG"); \
  if (isDebug != NULL && !strcasecmp(isDebug, "y")) { \
    fprintf(stderr, __VA_ARGS__); \
  } \
} while (0);

int main(int argc, char const *argv[]) {
  char *filename = "output.txt";
  FILE *output;
  output = fopen(filename, "a");
  int character;
  while (1) {
    character = fgetc(stdin);
    if (feof(stdin)) {
      break;
    }
    fputc(character, output);
  }
  fclose(output);
  printDebug("output = %p\n", output)
}
