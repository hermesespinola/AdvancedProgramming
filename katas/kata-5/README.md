# Word Cloud

You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴, where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

  > "After beating the eggs, Dana read the next step:"

  > "Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 2.

2. Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".

Assume the input will only contain words and standard punctuation.

### Context:
With a hash table we can create an histogram where the key is
the word and the number of repetitions is the value. Before
inserting the word we preprocess it to turn it to lowercase
and to remove punctuation marks from the end of the
word `{'.', ',', ':', ';', '!', '?'}`. We insert it in the hash table if it is not
already there. If it exists we add one to the value
that is already there.
The solution is `O(n)` assuming that reading a file word by
word is also `O(n)` and string operations `tolower` and
`strlen` are also `O(n)`. The insert and get of a hash table is
`O(1 + alpha)` where alpha is a small constant. We just iterate
the input once.

### Break down:
1. Initialize a hash table.
1. Read the input file word by word until you find the end of file or read no word.
2. Take the current word and remove the final
punctuation mark (if exist) and convert it to
lowercase.
3. If the word is a key in the hash table sum one to the value,
otherwise insert this word as a key with a value of one.
