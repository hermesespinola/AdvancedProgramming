# Judge Route Circle

Validate if a given string is numeric.

Some examples:
`"0"` => `true`
`" 0.1 "` => `true`
`"abc"` => `false`
`"1 a"` => `false`
`"2e10"` => `true`

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

### Context:
Numbers can contain only digits, dots, `-` and `+` at the beginning and spaces
at the beginning and end. Numbers can start with any digit (including 0), `-`,`+` and a dot.
Numbers can end with any digit or a dot.
The letter `e` is special because it means that whatever
is to the left is `x10^` whatever is on the right, numbers to the right of `e` can
have `-` at the start but not `+`.
This code does not accept commas.

Here are some tests:
```
test(1, "123", true);
test(2, " 123 ", true);
test(3, "0", true);
test(4, "0123", true);
test(5, "00", true);
test(6, "-10", true);
test(7, "-0", true);
test(8, "123.5", true);
test(9, "123.000000", true);
test(10, "-500.777", true);
test(11, "0.0000001", true);
test(12, "0.00000", true);
test(13, "0.", true);
test(14, "00.5", true);
test(15, "123e1", true);
test(16, "1.23e10", true);
test(17, "0.5e-10", true);
test(18, "1.0e4.5", false);
test(19, "0.5e04", true);
test(20, "12 3", false);
test(21, "1a3", false);
test(22, "", false);
test(23, "     ", false);
test(24, NULL, false);
test(25, ".1", true);
test(26, ".", false);
test(27, "2e0", true);
test(28, "+.8", true);
test(29, " 005047e+6", true);
test(30, "3", true);
test(31, "e", false);
```

### Break down:
Code is divided in three sections.
1. Digits before the a dot. Where there can be several special character.
2. Digits after the dot, where there cannot be any special character but an `e`.
3. Digits after the `e`.
4. In each section there is a set of rules that must be met.
