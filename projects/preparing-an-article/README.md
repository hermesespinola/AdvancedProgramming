# Preparing an Article

### Description
The premise is simple, replace all opening quotation marks **"** by two single
left quotes **&#96;&#96;** and all closing quotation marks by two single right quotes **''**.
There are no nested quotations. If a quote is incomplete (no closing double quote)
in the same paragraph, delete the opening quote, a paragraph ends by at least
one line break or the `\par` TeX command (or both). Ignore `\"` commands since
these are used to produce dieresis.
The end of the input will always be marked by the `\endinput` command.

#### Sample
##### input
```
There is no "q in this sentence. \par
"Talk child," said the unicorn.

She s\"aid, "\thinspace `Enough!', he said."
\endinput
```

##### output
```
There is no q in this sentence. \par
``Talk child,'' said the unicorn.

She s\"aid, ``\thinspace `Enough!', he said.''
\endinput
```

### Context
The solution is `O(n)` since the code iterates the input once to find the
position of the quotation marks. As it is guaranteed that there are no nested
quotations, we can be greedy about dropping quotation marks, we drop the last
mark if the total number of quotation marks in a paragraph is not even. Also, if
we find the `\par` command we drop the last mark, if it's not even.

Then the code iterates again over the input line and writes the same contents,
but replacing the found quotes with the required characters, and dropping the
extra ones. At the end we just print the new lines.

***Note:*** the get_line function is the same as the `getline` from stdio.h but I
included it in the source code because non POSIX implementations of the c standard
don't include this function.

### Breakdown
1. Initialize the output array of strings and the output and input buffer.
2. Read a line from stdin and put it in the input buffer.
3. Read all the line and store the indices of the quotation marks in an array. with the following rules:
  - Don't add `"` following a `\`.
  - Don't add `"` that are part of a command.
  - Drop the last `"` if the number of `"` is even.
  - If you find a `\par` command, execute the previous rule.
4. Iterate over the input string, writing the same characters, except that if the current index is equal to the next quotation mark, write **&#96;&#96;** if the index is even and `''` if it's odd.
5. If you find a `"` that is not in the list and is not preceded by a `\` then don't write it to the buffer buffer.
6. If the line is equals to `\endinput` then go to **8**.
7. Copy the buffer output to the output array and move to the next line from **2** to **7**.
8. Print the whole output array to stdout, one new line for each string.
