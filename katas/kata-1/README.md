
# Find Anagram Mappings

Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given
```
A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
```

We should return

```
[1, 4, 3, 2, 0]
```

as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.

Note:

   A, B have equal lengths in range [1, 100].
   A[i], B[i] are integers in range [0, 10^5].


### Context:
The c solution is O(n^2) because the nums array is traversed twice, checking all
possible combinations to see if two numbers add up to target.

The c++ solution is solved with a set in linear time.
Just have check if the difference of the target minus a number in the list exists
in the set.

### Break down:
C++:
1. For every number *x* in *nums*, compare it with every unseen numbers in *nums*, *y*.
2. If *x + y == target* return the index of *x* and the index of *y*.

C++:
1. Fist create a set *s* and populate it with the given numbers *nums*.
2. For each number *x* in *nums*:
  - Calculate *y = target - x*.
  - Check if *y* exists in *s*.
  - If so, find the index of *y* in *nums* and return the index of *x* and *y*.
