/*
Problem Statement:
Write a C program that will remove white space from a string.

--------------------------------------------------
Sample Test Cases:

Input: Hello World
Output: HelloWorld

Input: Compiler Design Lab
Output: CompilerDesignLab

Input: I love C programming
Output: IloveCprogramming

Input: No Space
Output: NoSpace
--------------------------------------------------

Explanation:
This program reads characters one by one using getchar().

We use isspace() to check if a character is whitespace.
If it is NOT whitespace, we print it.
So effectively, all whitespace characters are removed.

Whitespace includes:
- space ' '
- tab '\t'
- newline '\n'
- etc.
*/

#include <stdio.h>
#include <ctype.h> // for isspace()

int main()
{
    int ch;

    // Read input character by character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Print only non-whitespace characters
        if (!isspace(ch))
        {
            putchar(ch);
        }
    }

    // Print newline for clean output
    printf("\n");

    return 0;
}