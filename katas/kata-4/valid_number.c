#include <stdio.h>
#include <stdbool.h>

bool isNumber(char* s) {
  if (s == NULL) {
    return 1;
  }
  int i;

  // Skip initial white spaces
  while (s[i] == ' ') {
    i++;
  }

  // Check that string is not over or starts with 'e'.
  if (s[i] == '\0') {
    return 1;
  }

  // Skip possible special first char
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }
  // A '+' or '-' can be followed by a dot
  if (s[i] == '.') {
    i++;
  }

  // Check that it has at least one digit
  if (s[i] < '0' || s[i] > '9') {
    return 1;
  }
  i++;

  // Check that all characters are numbers (exit loop when a dot or 'e' is seen)
  while (s[i] != '\0' && s[i] != ' ' && s[i] != '.' && s[i] != 'e') {
    if (s[i] < '0' || s[i] > '9') {
      return 1;
    }
    i++;
  }

  if (s[i] == '.') {
    i++;
    while (s[i] != '\0' && s[i] != ' ' && s[i] != 'e') {
      if (s[i] < '0' || s[i] > '9') {
        return 1;
      }
      i++;
    }
  }

  // Check exponential numbers
  if (s[i] == 'e') {
    i++;
    // Skip possible special first char, no dot here
    if (s[i] == '-' || s[i] == '+') {
      i++;
    }
    // This is the last posible sequence of digits
    while (s[i] != '\0' && s[i] != ' ') {
      if (s[i] < '0' || s[i] > '9') {
        return 1;
      }
      i++;
    }
  }

  // check that all remaining characters are white spaces
  if (s[i] == ' ') {
    while (s[i] == ' ') {
      i++;
    }

    if (s[i] != '\0') {
      return 1;
    }
  }

  return 0;
}

void test(int number, char *arg, int expected) {
  int result = isNumber(arg);
  if (result == expected) {
    printf("Test #%i: PASSED\n", number);
  } else {
    printf("Test #%i: FAILED\n", number);
    printf("Test #%i: FAILED, expected %i but got %i with argument %s\n", number, expected, result, arg);
  }
}

int main(int argc, char const *argv[]) {
  test(1, "123", 0);
  test(2, " 123 ", 0);
  test(3, "0", 0);
  test(4, "0123", 0);
  test(5, "00", 0);
  test(6, "-10", 0);
  test(7, "-0", 0);
  test(8, "123.5", 0);
  test(9, "123.000000", 0);
  test(10, "-500.777", 0);
  test(11, "0.0000001", 0);
  test(12, "0.00000", 0);
  test(13, "0.", 0);
  test(14, "00.5", 0);
  test(15, "123e1", 0);
  test(16, "1.23e10", 0);
  test(17, "0.5e-10", 0);
  test(18, "1.0e4.5", 1);
  test(19, "0.5e04", 0);
  test(20, "12 3", 1);
  test(21, "1a3", 1);
  test(22, "", 1);
  test(23, "     ", 1);
  test(24, NULL, 1);
  test(25, ".1", 0);
  test(26, ".", 1);
  test(27, "2e0", 0);
  test(28, "+.8", 0);
  test(29, " 005047e+6", 0);
  test(30, "3", 0);
  test(31, "e", 1);
  return 0;
}
