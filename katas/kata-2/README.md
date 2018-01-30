
# Strong password checker

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

### Context
The Solution is O(n) because it only traverses the string once. But it is not correct sice it does not give the correct result for all cases where the length of the password is greater than 20.

### Breakdown
There are two cases:
- `len` <= 20:
  + Just count the number of errors (has upper, has lower, has digit) in the string and the missing characters and calculate the min number of changes required.
- `len` > 20:
  + Count the number of errors and the number of repeating characters and the number of 
required deleted characters, then calculate the minimum number of changes given that information.
