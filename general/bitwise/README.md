#Bitwise operators

| Type of Bitwise Operator | Symbol | Operation                                     |
|--------------------------|--------|-----------------------------------------------|
| AND                      | &      | Sets bits that are 1 in both operands         |
| OR                       | |      | Sets bits that are 1 in either operand        |
| XOR                      | ^      | Sets bits that are 1 in only one operand      |
| NOT                      | ~      | Inverts bits                                  |
| Left Shift               | <<     | Shifts bits left (multiplies by 2^n)          |
| Right Shift              | >>     | Shifts bits right (divides by 2^n)            |



# Exercises
## Exercise 1: Swap Two Numbers Using XOR

### Problem:
Write a C++ program to swap two numbers without using a temporary variable, only using the XOR (^) operator.

### Expected Output Example:
```
Before swapping: a = 10, b = 20
After swapping: a = 20, b = 10
```
## Exercise 2: Check if a Number is a Power of 2

### Problem:
Write a function to check whether a given number is a power of 2 using bitwise operators.

Hint:

    A number n is a power of 2 if n & (n - 1) == 0 and n > 0.

### Example Inputs & Outputs:
```
Input: 8
Output: 8 is a power of 2

Input: 7
Output: 7 is not a power of 2
```

## Exercise 3: Count the Number of 1s in a Binary Representation (Hamming Weight)

### Problem:
Write a function that counts the number of 1s in the binary representation of an integer.

### Example Inputs & Outputs:
```
Input: 9  (1001 in binary)
Output: 2

Input: 15 (1111 in binary)
Output: 4
```

## Exercise 4: Extract the K-th Bit of a Number

### Problem:
Write a function that takes an integer num and an integer k, then extracts and prints the k-th bit (0-based index, from right).

### Example Inputs & Outputs:
```
Input: num = 13 (1101 in binary), k = 1
Output: 1

Input: num = 13 (1101 in binary), k = 2
Output: 0
```

## Exercise 5: Toggle a Specific Bit

### Problem:
Write a program to toggle (flip) the k-th bit of a given number and print the new number.

### Example Inputs & Outputs:
```
Input: num = 13 (1101 in binary), k = 1
Output: 15 (1111 in binary)

Input: num = 13 (1101 in binary), k = 2
Output: 9  (1001 in binary)
```
