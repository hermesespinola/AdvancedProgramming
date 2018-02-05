#include <string.h>
#include <stdio.h>

int judgeCircle(char* moves) {
  int delta_x = 0;
  int delta_y = 0;
  int len = strlen(moves);

  for (int i = 0; i < len; i++) {
    if (moves[i] == 'R') {
      delta_x += 1;
    } else if (moves[i] == 'L') {
      delta_x -= 1;
    } else if (moves[i] == 'U') {
      delta_y += 1;
    } else if (moves[i] == 'D') {
      delta_y -= 1;
    }
  }

  return delta_x == 0 && delta_y == 0;
}

int main(int argc, char const *argv[]) {
  judgeCircle((char *) argv[1]);
  return 0;
}
