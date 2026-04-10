/*
Problem Statement:
Write a C program that will take multiple lines as input and remove the single-line and multi-line comments if there are any.

--------------------------------------------------
Sample Test Cases:

Input:
int x = 5;
// this is a comment
int y = 10;
int z = x + y; // inline comment

Output:
int x = 5;
int y = 10;
int z = x + y;

Input:
int x = 5;
/* this is a
   multi line
   comment * /
int y = 10;
int z = x + y;

Output:
int x = 5;
int y = 10;
int z = x + y;

Input:
int x = 5; // inline
/* block
comment * /
int y = 10;
// full line comment
int z = x + y;

Output:
int x = 5;
int y = 10;
int z = x + y;

Input:
int a = 10;
int b = 20;
printf("Hello");

Output:
int a = 10;
int b = 20;
printf("Hello");
--------------------------------------------------

Explanation:
This program removes comments from C source code.

Types of comments handled:

1. Single-line comment:
   Starts with '//' and continues until end of line

2. Multi-line comment:
   Starts with '/*' and ends with '* /'

Core Idea:
- Read input line by line
- Traverse each character
- Skip characters that belong to comments
- Print only valid code

State Used:
- inMultiLineComment:
  → 0 = normal code
  → 1 = inside multi-line comment

Note:
- "* /" is written with space to avoid nested comment issue in this block
- Program stops when an empty line is entered
*/

#include <stdio.h>

int main()
{
    char line[1000];
    int i, ch;
    int inMultiLineComment = 0;

    while (1)
    {
        i = 0;

        // read one line
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            line[i++] = ch;
        }

        // break ONLY if EOF
        if (ch == EOF && i == 0)
            break;

        line[i] = '\0';

        int j = 0;
        int printedSomething = 0; // track if we printed anything

        while (j < i)
        {
            if (inMultiLineComment)
            {
                if (line[j] == '*' && line[j + 1] == '/')
                {
                    inMultiLineComment = 0;
                    j += 2;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if (line[j] == '/' && line[j + 1] == '/')
                {
                    break;
                }
                else if (line[j] == '/' && line[j + 1] == '*')
                {
                    inMultiLineComment = 1;
                    j += 2;
                }
                else
                {
                    putchar(line[j]);
                    printedSomething = 1;
                    j++;
                }
            }
        }

        // print newline ONLY if something was printed
        if (printedSomething)
            putchar('\n');

        if (ch == EOF)
            break;
    }

    return 0;
}