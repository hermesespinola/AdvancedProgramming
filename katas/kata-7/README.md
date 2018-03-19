# Word Cloud

### Game Input
The program must first read the initialization data from standard input. Then, within an infinite loop, read the device data from the standard input and provide to the standard output the next movement instruction.
Initialization input

**Line 1** : 2 integers `W` `H`. The (`W`, `H`) couple represents the width and height of the building as a number of windows.

**Line 2** : 1 integer `N`, which represents the number of jumps Batman can make before the bombs go off.

**Line 3** : 2 integers `X0` `Y0`, representing the starting position of Batman.

###### Input for one game turn
The direction indicating where the bomb is.
- `U` (Up)
- `UR` (Up-Right)
- `R` (Right)
- `DR` (Down-Right)
- `D` (Down)
- `DL` (Down-Left)
- `L` (Left)
- `UL` (Up-Left)


###### Output for one game turn
A **single line** with 2 integers `X` `Y` separated by a space character. (`X`, `Y`) represents the location of the next window Batman should jump to. `X` represents the index along the horizontal axis, `Y` represents the index along the vertical axis. (0,0) is located in the top-left corner of the building.

###### Constraints
1 ≤ `W` ≤ 10000
1 ≤ `H` ≤ 10000
2 ≤ `N` ≤ 100
0 ≤ `X`, `X0` < W
0 ≤ `Y`, `Y0` < H
Response time per turn ≤ 150ms
Response time per turn ≤ 150ms

### Context:
We need to find the bomb before the time runs out, that's why
we cannot use a linear search. We'll use binary search.
If we receive a `L` it's guaranteed that we'll receive `L` for
all positions to the left of our current position.
If we receive a `U` it's guaranteed that we'll receive `U` for
all positions above of our current position, and so on.
That means that if we receive an `L` we can constraint the
search to the right subspace from our position, and so on for
all directions. Each turn we must move to the middle position
between our current position and the limit of the direction we
must go to. It's worth noting that search is independent in
each axis, that means we will perform two binary searches at
the same time.

- `leftLimit` is the limit of the search space to the left.
- `rightLimit` is the limit of the search space to the right.
- `downLimit` is the limit of the search space below.
- `upLimit` is the limit of the search space above.
### Break down:
1. Initialization:
  - `leftLimit = 0`.
  - `rightLimit = W + 1` (to compensate 0-based indexes).
  - `downLimit = H + 1`(to compensate 0-based indexes).
  - `upLimit = 0`.
2. Read input to `bombDir`.
3. Update limits.
  - if `bombDir` contains `U` update `downLimit` to the
    current `Y`.
  - if `bombDir` contains `D` update `upLimit` to the
    current `Y` plus one (so that we can get 0 as the result
    of other operations).
  - if `bombDir` contains `R` update `leftLimit` to the
    current `X` plus one (so that we can get 0 as the result
    of other operations).
  - if `bombDir` contains `L` update `rightLimit` to the
    current `X`.
4. Update current position.
  - if `bombDir` contains `U` subtract `Y -= (Y - upLimit) / 2 + 1` to Y.
  - if `bombDir` contains `D` add `(downLimit - Y) / 2` to Y.
  - if `bombDir` contains `R` add `(rightLimit - X) / 2` to X.
  - if `bombDir` contains `L` subtract `(X - leftLimit) / 2 + 1` to X.
5. Repeat from step 2 until solution is found.
