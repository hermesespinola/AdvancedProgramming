#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 100
#define MAX_IN_SIZE MAX_WORD_SIZE * MAX_LINE_SIZE

void substrcpy(char *source, char *target, int fromSource, int toSource, int fromTarget) {
  for (int i = 0; i < toSource - fromSource; i++) {
    char c = source[fromSource + i];
    target[fromTarget + i] = c;
  }
}

char * reverse_order(char *line) {
  int words_end[MAX_WORD_SIZE];
  int n_words = 0, len = 0;

  for (int i = 0; i < MAX_IN_SIZE; i++) {
    char c = line[i];
    if (c == '\0') {
      words_end[n_words++] = i;
      len++;
      break;
    } else if (c == ' ') {
      words_end[n_words++] = i;
    }
    len++;
  }

  char *result = malloc(len * sizeof(char));

  int word_start = 0, word_end, targetPos, i;
  for (i = 0; i < n_words; i++) {
    word_end = words_end[i];
    targetPos = len - word_end - 1;
    substrcpy(line, result, word_start, word_end, targetPos);
    result[targetPos + (word_end - word_start)] = ' ';
    word_start = word_end + 1;
  }

  result[len - 1] = '\0';
  return result;
}

int main(int argc, char const *argv[]) {
  char *line = NULL;
  size_t len = 0;
  int num_test;

  scanf("%d", &num_test);
  for (unsigned i = 1; i < num_test + 1; i++) {
    char line[MAX_IN_SIZE];
    scanf(" %[^\n]", line);
    char *r = reverse_order(line);
    printf("%s\n", r);
  }

  return 0;
}
