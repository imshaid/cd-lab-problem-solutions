/*
Problem Statement:
Write a C program that will extract the digits from a string.

--------------------------------------------------
Sample Test Case:

Input:
I'm 26, Rafi is 20 and Hasan is 24.

Output:
26, 20, 24
--------------------------------------------------

Explanation:
This program extracts numbers from a string.

Approach:
- Read input character by character
- If digit found → print it
- If non-digit comes after digits → print comma
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;
    int inNumber = 0; // flag to track if we are inside a number
    int first = 1;    // to control comma printing

    // Step 1: Read input
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (isdigit(ch))
        {
            // if starting a new number
            if (!inNumber)
            {
                if (!first)
                {
                    printf(", ");
                }
                first = 0;
                inNumber = 1;
            }

            printf("%c", ch); // print digit
        }
        else
        {
            // if we were in a number and now ended
            if (inNumber)
            {
                inNumber = 0;
            }
        }
    }

    return 0;
}