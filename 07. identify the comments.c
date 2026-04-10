/*
Problem Statement:
Write a C program that will take multiple lines as input and identify the comments if there are any.

--------------------------------------------------
Sample Test Cases:

Input:
int a = 5; // this is a variable
/* multi-line
comment * /
printf("Hello");int x = 5;
// this is a comment
int y = 10;
/* multi line start
this is still comment * /
int z = x + y;

Output:
Line 1: [SINGLE-LINE COMMENT]        --> // this is a variable
Line 2: [MULTI-LINE COMMENT START]   --> /* multi-line
Line 3: [MULTI-LINE COMMENT END]     --> comment * /
Line 4: [CODE]                       --> printf("Hello");int x = 5;
Line 5: [SINGLE-LINE COMMENT]        --> // this is a comment
Line 6: [CODE]                       --> int y = 10;
Line 7: [MULTI-LINE COMMENT START]   --> /* multi line start
Line 8: [MULTI-LINE COMMENT END]     --> this is still comment * /
Line 9: [CODE]                       --> int z = x + y;

-----------------------------------
Total lines    : 9
Total comments : 4

Input:
int a = 10;
int b = 20;
printf("Hello");

Output:
Line 1: [CODE]                       --> int a = 10;
Line 2: [CODE]                       --> int b = 20;
Line 3: [CODE]                       --> printf("Hello");

-----------------------------------
Total lines    : 3
Total comments : 0

Input:
// first comment
/* multi-line start
end * /

Output:
Line 1: [SINGLE-LINE COMMENT]        --> // first comment
Line 2: [MULTI-LINE COMMENT START]   --> /* multi-line start
Line 3: [MULTI-LINE COMMENT END]     --> end * /

-----------------------------------
Total lines    : 3
Total comments : 2

Input:
int x = 5; // inline comment
/* start * /
int y = 10;

Output :
Line 1: [SINGLE-LINE COMMENT]        --> // inline comment
Line 2: [MULTI-LINE COMMENT START]   --> /* start * /
Line 3: [CODE]                       --> int y = 10;

-----------------------------------
Total lines    : 3
Total comments : 2

--------------------------------------------------
Explanation : This program reads input line by line and identifies different types of comments.

Types of comments : 1. Single -
line comment : Starts with '//' and continues until end of line

2. Multi -
line comment : Starts with '/*' and ends with '* /'

Logic : -Each line is scanned character by character -
If '//' is found → single - line comment - If '/*' is found → multi - line comment start - If '* /' is found → multi - line comment end - Otherwise → treated as normal code

Note : -"* /" is written with space to avoid nested comment issues in this block -
Program stops when an empty line is entered
*/

#include <stdio.h>

int main()
{
    char line[1000];
    int lineNum = 0;
    int commentCount = 0;
    int i, ch;
    int hasContent = 0;

    while (1)
    {
        i = 0;

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            line[i++] = ch;
        }
        line[i] = '\0';

        if (i == 0)
            break;

        hasContent = 1;
        lineNum++;

        int foundComment = 0;

        // --- Single-line comment ---
        for (int j = 0; j < i - 1; j++)
        {
            if (line[j] == '/' && line[j + 1] == '/')
            {
                commentCount++;

                printf("Line %d: ", lineNum);
                printf("%-28s --> ", "[SINGLE-LINE COMMENT]");

                for (int k = j; k < i; k++)
                    printf("%c", line[k]);

                printf("\n");
                foundComment = 1;
                break;
            }
        }

        // --- Multi-line comment start ---
        if (!foundComment)
        {
            for (int j = 0; j < i - 1; j++)
            {
                if (line[j] == '/' && line[j + 1] == '*')
                {
                    commentCount++;

                    printf("Line %d: ", lineNum);
                    printf("%-28s --> ", "[MULTI-LINE COMMENT START]");

                    for (int k = j; k < i; k++)
                        printf("%c", line[k]);

                    printf("\n");
                    foundComment = 1;
                    break;
                }
            }
        }

        // --- Multi-line comment end ---
        if (!foundComment)
        {
            for (int j = 0; j < i - 1; j++)
            {
                if (line[j] == '*' && line[j + 1] == '/')
                {
                    printf("Line %d: ", lineNum);
                    printf("%-28s --> ", "[MULTI-LINE COMMENT END]");

                    for (int k = 0; k <= j + 1; k++)
                        printf("%c", line[k]);

                    printf("\n");
                    foundComment = 1;
                    break;
                }
            }
        }

        // --- Code ---
        if (!foundComment)
        {
            printf("Line %d: ", lineNum);
            printf("%-28s --> %s\n", "[CODE]", line);
        }
    }

    printf("\n-----------------------------------\n");

    if (!hasContent)
    {
        printf("No input given.\n");
    }
    else
    {
        printf("Total lines    : %d\n", lineNum);
        printf("Total comments : %d\n", commentCount);
    }

    return 0;
}