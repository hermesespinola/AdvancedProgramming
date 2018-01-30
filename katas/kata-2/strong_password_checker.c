#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MIN_LENGTH 6
#define MAX_LENGTH 20
#define MIN_LOWER 'a'
#define MAX_LOWER 'z'
#define MIN_UPPER 'A'
#define MAX_UPPER 'Z'
#define MIN_DIGIT '0'
#define MAX_DIGIT '9'
#define MAX_REPEATING 3

bool btwn(int lowerbound, int el, int upperbound) {
  return el >= lowerbound && el <= upperbound;
}

int max(int a, int b) {
  if (a > b) return a;
  else return b;
}

int strongPasswordChecker(char* s) {
  int i = 0, repetition = 0, num_repeating = 0;
  bool has_lowercase = false, has_uppercase = false, has_digit = false;
  int len = strlen(s);
  int reps[len + 1];
  char prev = 0;

  for (int i = 0; i < len;) {
    if (!has_lowercase && btwn(MIN_LOWER, s[i], MAX_LOWER)) {
        has_lowercase = true;
    }
    if (!has_uppercase && btwn(MIN_UPPER, s[i], MAX_UPPER)) {
      has_uppercase = true;
    }
    if (!has_digit && btwn(MIN_DIGIT, s[i], MAX_DIGIT)) {
      has_digit = true;
    }

    int j = i, num = 0;
    while (i < len && s[i] == s[j]) {
      i++;
      num++;
    }

    num_repeating += num / MAX_REPEATING;

    reps[j] = i - j;
    prev = s[i-1];
  }

  int num_errors = !has_lowercase + !has_digit + !has_uppercase;
  if (btwn(0, len, MAX_LENGTH)) {
    int missing = max(0, MIN_LENGTH - len);
    printf("len: %d, missing: %d, num_errors: %d, num_repeating: %d\n", len, missing, num_errors, num_repeating);
    int required_changes = max(missing, num_repeating);
    if (required_changes >= num_errors) {
      return required_changes;
    } else {
      return max(required_changes, num_errors);
    }
  } else {
    int over = max(0, len - MAX_LENGTH), left = 0;
    for (int k = 1; k < 3; ++k) {
        for (int i = 0; i < len && over > 0; ++i) {
            if (reps[i] < 3 || reps[i] % 3 != (k - 1)) continue;
            reps[i] -= k;
            over -=k;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (reps[i] >= 3 && over > 0) {
            int need = reps[i] - 2;
            reps[i] -= over;
            over -= need;
        }
        if (reps[i] >= 3) left += reps[i] / 3;
    }
    return over + max(num_errors, left);
  }
}

int main(int argc, char const *argv[]) {
  char *pass = (char *) argv[1];
  char *msg = "is";
  int changesRequired = strongPasswordChecker(pass);
  if (changesRequired != 0) {
    msg = "is not";
  }
  printf("%s %s strong enough\n", pass, msg);
  printf("Minumum changes required %i\n", changesRequired);
  return 0;
}
