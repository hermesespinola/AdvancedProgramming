#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "hash.h"

bool f(int flight_length, int nMovies, int *movie_lengths) {
  HashInt movies;
  hashInit(&movies, nMovies);
  int i;
  for (i = 0; i < nMovies; i++) {
    hashInsert(&movies, movie_lengths[i], i);
  }

  for (i = 0; i < nMovies; i++) {
    int l = movie_lengths[i];
    int search = flight_length - l;
    int *solutionIdx = hashGet(&movies, search);
    if (solutionIdx != NULL && l > 0) {
      int solutionLenght = movie_lengths[*solutionIdx];
      if (*solutionIdx != i && solutionLenght > 0) {
        printf("Solution: %d + %d = %d\n", l, solutionLenght, flight_length);
        return true;
      } else {
        printf("Invalid solution: %d + %d = %d\n", l, solutionLenght, flight_length);
      }
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int fl = 2400;
  const int nMovies = 19;
  int mls[nMovies] = { -10, 2, 3, 4, 1200, 9, 10, 24, 188, 1098, 394, 9183, 489, 9238, 1283, 65, 1302, 893, 2410 };
  if (f(fl, nMovies, mls)) {
    printf("two movies found\n");
  } else {
    printf("two movies NOT found\n");
  }
}
