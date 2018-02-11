#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SYMB 80
#define MAX_LINES 150
#define END "\\endinput"

size_t get_line(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}

int main() {
  char **output = malloc(MAX_LINES * sizeof(char *));
  char *line = NULL;
  size_t size, i, j, num_lines = 0;
  char buffer[MAX_SYMB * 2 + 2];

  do {
    if (get_line(&line, &size, stdin) == -1) {
      printf("No line\n");
    } else {
      size_t len = strlen(line);
      line[len - 1] = 0;
      int n_quotes = 0, buffer_quotes = 0;
      int *quotes = malloc(len * sizeof(int));

      bool in_command = false;
      for (int i = 0; i < len; i++) {
        if (line[i] == '\\') {
          in_command = true;
          // if par command, remove the last quote if not closed
          if (i + 3 < len && line[i + 1] == 'p' && line[i + 2] == 'a' &&
              line[i + 3] == 'r' && n_quotes % 2 != 0) {
            n_quotes -= 1;
          }
        } else if (line[i] == ' ') {
          in_command = false;
        } else if (!in_command && line[i] == '"') {
          quotes[n_quotes++] = i;
        }
      }

      if (n_quotes % 2 != 0) {
        n_quotes--;
      }

      printf("There are %i quotation marks in this sentence\n", n_quotes);

      for (int i = 0; i < len; i++) {
        if (buffer_quotes < n_quotes && i == quotes[buffer_quotes]) {
          if (buffer_quotes % 2 == 0) {
            buffer[j++] = '`';
            buffer[j++] = '`';
          } else {
            buffer[j++] = '\'';
            buffer[j++] = '\'';
          }
          buffer_quotes++;
        } else {
          if (line[i] != '"') {
            buffer[j++] = line[i];
          } else if (i > 0 && line[i - 1] == '\\') {
            buffer[j++] = line[i];
          }
        }
      }

      output[num_lines] = malloc((j + 1) * sizeof(char));
      strncpy(output[num_lines++], buffer, j);
      n_quotes = 0;
    }
    j = 0;
  } while(strcmp(line, "\\endinput") != 0);

  for (int i = 0; i < num_lines; i++) {
    printf("%s\n", output[i]);
  }

  return 0;
}
