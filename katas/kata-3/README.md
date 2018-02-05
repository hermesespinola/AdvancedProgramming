# Judge Route Circle

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to **the original place**.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are `R` (Right), `L` (Left), `U` (Up) and `D` (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

```
Input: "UD"
Output: true
```

Example 2:

```
Input: "LL"
Output: false
```

### Context:
This problem is very simple. All I had to do is keep track of the robot's x and y movement (since it can only move in the x and y axis), At the end, if the total movement was zero, then return true. The problem is `O(n)` since I only needed to iterate once in the string, also this solution is `O(1)` in space complexity since I only keep have two variables.

### Break down:
1. Initialize `delta_x` and `delta_y` to zero.
2. Scan each character in the `moves` string.
  - If the character is `R` add one to `delta_x`.
  - If the character is `L` rest one to `delta_x`.
  - If the character is `U` add one to `delta_y`.
  - If the character is `D` rest one to `delta_y`.
3. If both `delta_x` and `delta_y` are zero, return true.
