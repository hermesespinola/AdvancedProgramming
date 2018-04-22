# Problem Title
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
  - For 1-byte character, the first bit is a 0, followed by its unicode code.

  - For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

| Char. number range (hexadecimal)  |        UTF-8 octet (binary) sequence |
|-----------------------------------|------------------------------|
|     0000 0000-0000 007F | 0xxxxxxx |
|     0000 0080-0000 07FF | 110xxxxx 10xxxxxx |
|     0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx |
|     0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx |

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

> **Note:** The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

**Example 1:**
```
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.    Return true.  It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
```

**Example 2:**
```
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.    Return false.  The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.  The next byte is a continuation byte which starts with 10 and that's correct.  But the second continuation byte does not start with 10, so it is invalid.
```

### Context:
All we have to do is check that the rules described above are met by the data.
We just have to keep in mind that the data may contain multiple utf-8 sequences, not just one.
So, if the first bit is a zero, it's correct and we move on to the next element in the data.
If the first bit is a one, we have to count the first `k` ones and make sure that
there are at least two ones and no more than four. Then we move on and check that there are
at least `k - 1` elements left in `data`. If so, we just have to check that the two most
significant bits of the next `k - 1` elements are `10`. Then we are all good.
We can recursively check any remaining data.

### Break down:
1. Check the most significant bit of the first byte in the data. `msb = 0x80 & firstByte`.
2. If the most significant bit is zero and the dataSize is 1 we can return true.
3. If the most significant bit is not zero and the dataSize is grather than 1 we recursively call validUtf8 with data + 1 and dataSize - 1.
4. Else, we count the number of consecutive 1's in this byte.
5. If the number of ones is less than 2 or greater than 4 we can return false.
6. Check that the 2 most significant bits of each byte are `10`:  `(data[i] & 0xC0) >> 6 == 2`.
7. Then, if the dataSize is greater than the number of bytes we just checked, call recursively this function: `vaildUtf8(data + expectedBytes, dataSize - expectedBytes)` else return true.
