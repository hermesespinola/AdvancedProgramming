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
  char *search = "mundo";
  char *replace = "MUNDOMUNDO";
  char word[255];
  int search_pos, character;
  FILE *input = fopen(filename, "r");
  while (1) {
    fscanf(input, "%s", word);
    printf("%s\n", word);
    if (feof(input)) {
      break;
    }
    if (strcmp(word, search) == 0) {
      fseek(input, -strlen(search), SEEK_CUR);
      search_pos = ftell(input);
      printDebug("Found %s at %d\n", word, search_pos);
      rewind(input);
      while (ftell(input) != search_pos) {
        character = fgetc(input);
        fputc(character, stdin);
      }
    }
  }
  fclose(input);
  printDebug("input = %p\n", input)
}
