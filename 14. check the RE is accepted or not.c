/*
Problem Statement:
Write a C program that takes user input and checks whether
it is accepted by a given Regular Expression (RE).

RE Used:
a*b

Meaning:
- zero or more 'a'
- followed by exactly one 'b'

--------------------------------------------------
Sample Test Cases:

Input:
aaab

Output:
Accepted

Input:
b

Output:
Accepted

Input:
aabbb

Output:
Rejected

Input:
abc

Output:
Rejected
--------------------------------------------------

Explanation:
This program simulates a simple DFA for the RE a*b.

Logic:
1. Read input
2. Check all characters before last are 'a'
3. Check last character is 'b'
4. If both conditions satisfied → Accepted
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i = 0, ch;

    // Step 1: Input
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[i++] = ch;
    }
    str[i] = '\0';

    int len = strlen(str);

    // Step 2: Empty check
    if (len == 0)
    {
        printf("Rejected\n");
        return 0;
    }

    // Step 3: Check last character = 'b'
    if (str[len - 1] != 'b')
    {
        printf("Rejected\n");
        return 0;
    }

    // Step 4: Check all previous are 'a'
    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] != 'a')
        {
            printf("Rejected\n");
            return 0;
        }
    }

    // Accepted
    printf("Accepted\n");

    return 0;
}