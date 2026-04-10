/*
Problem Statement:
Write a C program that will tokenize a string WITHOUT using any library function.

--------------------------------------------------
Sample Test Cases:

Input: Hello world
Output:
Hello
world

Total tokens: 2

Input: I love C programming
Output:
I
love
C
programming

Total tokens: 4

Input: Compiler Design Lab
Output:
Compiler
Design
Lab

Total tokens: 3

Input: Hello
Output:
Hello

Total tokens: 1
--------------------------------------------------

Explanation:
This program manually scans the string character by character.

Logic:
- If character is NOT delimiter → print it
- If delimiter found → print newline (end of token)

Delimiters:
- space ' '
- comma ','
- tab '\t'
- newline '\n'
*/

#include <stdio.h>

int isDelimiter(char ch)
{
    return (ch == ' ' || ch == ',' || ch == '\t' || ch == '\n');
}

int main()
{
    char str[1000];
    int i = 0, count = 0;

    fgets(str, sizeof(str), stdin);

    // remove newline character from fgets
    int j = 0;
    while (str[j] != '\n' && str[j] != '\0')
        j++;
    str[j] = '\0';

    // tokenize manually
    while (str[i] != '\0')
    {
        if (isDelimiter(str[i]))
        {
            // if previous char was not delimiter → end of token
            if (i > 0 && !isDelimiter(str[i - 1]))
            {
                printf("\n");
            }
        }
        else
        {
            // if start of a new token → increase count
            if (i == 0 || isDelimiter(str[i - 1]))
            {
                count++;
            }

            printf("%c", str[i]);
        }
        i++;
    }

    printf("\n\nTotal tokens: %d\n", count);

    return 0;
}