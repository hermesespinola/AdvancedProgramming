# Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,  
return [0, 1].
```

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
