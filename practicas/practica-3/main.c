#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int numberOfSegments;
  int totalTime;

  int *distances;
  int *speeds;

  scanf("%d %d", &numberOfSegments, &totalTime);

  distances = (int *) malloc(sizeof(int) * numberOfSegments);
  speeds = (int *) malloc(sizeof(int) * numberOfSegments);

  for (size_t i = 0; i < numberOfSegments; i++) {
    scanf("%d %d", &distances[i], &distances[i]);
  }
  return 0;
}
