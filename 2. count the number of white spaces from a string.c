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
This program reads a string character by character using getchar().
It counts the number of white space characters.

White space includes:
- Space ' '
- Tab '\t'
- Newline '\n' (optional, here we stop at newline)

We mainly count spaces and tabs in this program.
*/

#include <stdio.h>

int main()
{
    int ch;             // to store each character
    int whitespace = 0; // counter for white spaces

    printf("Enter a string: ");

    // Read input character by character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Check for space or tab
        if (ch == ' ' || ch == '\t')
        {
            whitespace++;
        }
    }

    // Output result
    printf("Number of white spaces: %d\n", whitespace);

    return 0;
}