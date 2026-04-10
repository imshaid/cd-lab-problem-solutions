/*
Problem Statement:
Write a C program that will tokenize a string using strtok().

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
This program uses strtok() to split a string into tokens.

Delimiters used:
- space ' '
- comma ','
- tab '\t'

strtok() modifies the original string and returns tokens one by one.
*/

#include <stdio.h>
#include <string.h> // for strtok()

int main()
{
    char str[1000];
    int count = 0;

    // printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove newline character left by fgets
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    str[i] = '\0';

    // tokenize using space as delimiter
    char *token = strtok(str, " ");

    // Extract tokens one by one
    while (token != NULL)
    {
        count++;
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    printf("\nTotal tokens: %d\n", count);

    return 0;
}