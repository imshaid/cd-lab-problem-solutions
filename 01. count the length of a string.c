/*
Problem Statement:
Write a program that will count the length of a string.

Additional Requirement:
Use dynamic memory allocation instead of fixed-size arrays (e.g., avoid char str[100]).

--------------------------------------------------
Sample Test Cases:

Input: Hello
Output: Length of the string: 5

Input: Compiler Design Lab
Output: Length of the string: 19

Input: I love C programming
Output: Length of the string: 20

Input: (empty input)
Output: Length of the string: 0
--------------------------------------------------

Explanation:
This program calculates the length of a string without storing it in a fixed-size array.

Instead of using dynamic memory (malloc), we directly read characters one by one
from input using getchar(). Each character increases the length counter.

Key Idea:
- We read input until we encounter:
    '\n'  → newline (user presses Enter)
    EOF   → End Of File (important for file input or redirected input)

- Each valid character increments the length.

Why this approach?
- No fixed-size array → avoids memory limitation
- No need for dynamic allocation → simple and efficient
- Works well for both keyboard input and file input

Note:
- Spaces are also counted as characters
- Empty input will return length = 0
*/

#include <stdio.h>

int main()
{
    int length = 0; // variable to store length of string
    int ch;         // variable to store each character (as integer)

    // Reading input character by character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        length++; // increment length for each character
    }

    // Output the final length
    printf("Length of the string: %d\n", length);

    return 0;
}