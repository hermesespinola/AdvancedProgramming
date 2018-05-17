#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  double start;
  double speed;
} horse_t;

int compareStart(const void *p1, const void *p2) {
  horse_t *h1 = (horse_t *)p1;
  horse_t *h2 = (horse_t *)p2;
  return h1->start - h2->start;
}

double cruiseControl(int dest, horse_t *horses, int nHorses) {
  for (size_t i = nHorses - 1; i > 0; i--) {
    horse_t h1 = horses[i], h2 = horses[i -1];
    if (h1.speed < h2.speed) {
      double intersection_time = (h1.start - h2.start) / (h2.speed - h1.speed);
      double intersection_point = h1.start + h1.speed * intersection_time;
      if (intersection_point < dest) {
        horses[i - 1] = horses[i];
      }
    }
  }

  horse_t final_horse = horses[0];
  double final_time = (dest - final_horse.start) / final_horse.speed;
  double annie_speed = dest / final_time;
  return annie_speed;
}

int main(int argc, char const *argv[]) {
  char *line = NULL;
  size_t len = 0;
  int num_test;

  scanf("%d", &num_test);
  for (unsigned i = 1; i < num_test + 1; i++) {
    int destination, nHorses;
    double start, speed;
    scanf("%d %d", &destination, &nHorses);

    horse_t horses[nHorses];
    for (unsigned j = 0; j < nHorses; j++) {
      scanf("%lf %lf", &start, &speed);
      horse_t horse = { start, speed };
      horses[j] = horse;
    }

    printf("Case #%d: %lf\n", i, cruiseControl(destination, horses, nHorses));
  }

  return 0;
}
