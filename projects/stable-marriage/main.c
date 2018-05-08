#include <stdio.h>
#include <stdlib.h>

void printResult(short unsigned *husbands, short unsigned size) {
  for (short unsigned woman = 1; woman < size + 1; woman++) {
    printf("%hd %d\n", woman, husbands[woman-1] + 1);
  }
}

int main(int argc, char const *argv[]) {
  char *line = NULL;
  short unsigned num_test;
  short int i, n;

  scanf("%hd\n", &num_test);
  for (short unsigned test = 0; test < num_test; test++) {
    short unsigned nMarriages;
    scanf("%hd\n", &nMarriages);

    short unsigned wPreferences[nMarriages][nMarriages];
    short unsigned mPreferences[nMarriages][nMarriages];
    short int *husbands = malloc(nMarriages * sizeof(short int));
    short unsigned w, pref, freeCount;
    short int m;

    for (n = 0; n < nMarriages; n++) {
      scanf("%hd ", &w);
      w = w - 1;
      for (pref = 0; pref < nMarriages; pref++) {
        if (pref == nMarriages - 1) {
          scanf("%hd\n", &m);
        } else {
          scanf("%hd ", &m);
        }
        wPreferences[w][pref] = m - 1;
      }
      scanf("\n");
    }

    for (n = 0; n < nMarriages; n++) {
      scanf("%hd ", &m);
      m = m - 1;
      for (pref = 0; pref < nMarriages; pref++) {
        if (pref == nMarriages - 1) {
          scanf("%hd\n", &w);
        } else {
          scanf("%hd ", &w);
        }
        mPreferences[m][pref] = w - 1;
      }
      scanf("\n");
    }

    for (n = 0; n < nMarriages; n++) {
      husbands[n] = -1;
    }

    freeCount = nMarriages;
    while (freeCount > 0) {
      for (n = 0; n < nMarriages; n++) {
        // check all preferences until we find someone is not married
        for (i = 0; i < nMarriages; i++) {
          w = mPreferences[n][i];
          m = husbands[w];

          // if w is married check her preferences.
          if (m > -1 && m < nMarriages) {
            // NOTE: This would be more efficient if wPreferences and mPreferences
            // were a ranking list, where the index represents the man, and the value
            // the rank, instead of a preference list.
            for (pref = 0; pref < nMarriages; pref++) {
              if (wPreferences[w][pref] == m) {
                break;
              } else if (wPreferences[w][pref] == n) { // if she prefers `n` then marry her.
                husbands[w] = n;
                break;
              }
            }
            // Stop search if we married.
            if (wPreferences[w][pref] == n) {
              break;
            }
          } else { // if w is not married, marry and stop search.
            husbands[w] = n;
            freeCount--;
            break;
          }
        }
      }
    }

    // flip the arrays to print them and pass the tests.
    short unsigned *wives = malloc(nMarriages * sizeof(short unsigned));
    for (short unsigned i = 0; i < nMarriages; i++) {
      wives[husbands[i]] = i;
    }
    printResult(wives, nMarriages);
  }

  return 0;
}
