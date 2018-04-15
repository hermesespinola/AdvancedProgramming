# Inflight Entertainment System
You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

When building your function:
 - Assume your users will watch exactly two movies
 - Don't make your users watch the same movie twice
 - Optimize for runtime over memory


### Context:
To avoid a *O(n^2)* solution, instead of looping once the array for each element
searching the solution, we can put all our data in a hash table, the key will be
the movie length and the value will be its index. Then, for each movie length *l*
in the table, we search for *x*, where `x = flight_length - l`. If it exists, we
we need to make sure that *l* and *x* are positive, and are different (they
don't have the same index) and return true. If we iterate all the movie_lengths
array and have found nothing, we can say that there is no two movies such that
there are two numbers in movie_lengths whose sum equals flight_length.

### Break down:
1. Initialize a hash table given the size of flight_length.
2. Insert all elements in flight_length in the hash table where the key is the length of the movie and the value is its index in flight_length.
3. For each `i` in the range of the length of flight_length:
 - `l = movie_lengths[i]`
 - The required movie length is `search = flight_length - l`
 - We search for this movie length in the hash table: `solutionIdx = hashGet(&movies, search)`
 - If it's non null, we found a possible solution, else, keep searching.
 - If `solutionIdx != i` and `movie_lengths[solutionIdx] > 0` then return true.
5. Return false.
