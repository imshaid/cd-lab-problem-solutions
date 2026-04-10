/*
Problem Statement:
Write a C program that will take multiple lines as input and count the number of lines.

--------------------------------------------------
Sample Test Cases:

Input:
Hello
World

Output:
Number of lines: 2

Input:
I
love
C
programming

Output:
Number of lines: 4

Input:
Compiler
Design
Lab

Output:
Number of lines: 3

Input:
Single line input
Output:
Number of lines: 1
--------------------------------------------------

Explanation:
This program reads input character by character using getchar().

Logic:
- Each time a newline character '\n' is found → it indicates end of a line
- So, we increment the line counter

Special Case:
- If the last line does NOT end with a newline (user presses EOF directly),
  we still count it as a valid line

Input termination:
- Linux/Mac → Ctrl + D
- Windows → Ctrl + Z
*/

#include <stdio.h>

int main()
{
    int ch;          // to store each character
    int lines = 0;   // line counter
    int hasChar = 0; // to check if input exists

    // Read input until EOF
    while ((ch = getchar()) != EOF)
    {
        hasChar = 1; // at least one character

        // If newline found → one line completed
        if (ch == '\n')
        {
            lines++;
        }
    }

    /*
    If:
    - there was input (hasChar = 1)
    - but last character was NOT '\n'

    Then:
    - last line wasn't counted → so increment lines
    */
    if (hasChar && ch != '\n')
    {
        lines++;
    }

    printf("Number of lines: %d\n", lines);

    return 0;
}