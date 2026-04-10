/*
Problem Statement:
Write a C program that will count the number of white spaces from a string.

--------------------------------------------------
Sample Test Cases:

Input: Hello World
Output: Number of white spaces: 1

Input: Compiler Design Lab
Output: Number of white spaces: 2

Input: I love C programming
Output: Number of white spaces: 3

Input: NoSpaceHere
Output: Number of white spaces: 0
--------------------------------------------------

Explanation:
This program reads input character by character using getchar().

We use the built-in function isspace() from <ctype.h> to check
whether a character is a whitespace or not.

isspace() returns true for:
- space ' '
- tab '\t'
- newline '\n'
- vertical tab '\v'
- form feed '\f'
- carriage return '\r'

We stop taking input at newline, so only spaces/tabs before Enter are counted.
*/

#include <stdio.h>
#include <ctype.h> // for isspace()

int main()
{
    int ch;             // to store each character
    int whitespace = 0; // counter

    // Read input character by character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Check if character is any whitespace
        if (isspace(ch))
        {
            whitespace++;
        }
    }

    // Output result
    printf("Number of white spaces: %d\n", whitespace);

    return 0;
}