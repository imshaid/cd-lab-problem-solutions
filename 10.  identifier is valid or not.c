/*
Problem Statement:
Write a C program to test whether a given identifier is valid or not.

--------------------------------------------------
Sample Test Cases:

Input:
variable1
Output:
Valid Identifier

Input:
1variable
Output:
Invalid Identifier

Input:
total_sum
Output:
Valid Identifier

Input:
float
Output:
Invalid Identifier (Keyword)

Input:
user-name
Output:
Invalid Identifier

Input:
(empty input)
Output:
Invalid Identifier

Input:
_
Output:
Valid Identifier

Input:
my@var
Output:
Invalid Identifier
--------------------------------------------------

Explanation:
This program checks whether a string is a valid C identifier.

Rules:
1. First character must be a letter (a-z, A-Z) or underscore (_)
2. Remaining characters can be letters, digits, or underscore
3. Identifier cannot be a keyword
4. No special characters allowed
*/

#include <stdio.h>

// function to check if a character is a letter
int isLetter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

// function to check if a character is a digit
int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

// function to check keyword (simple list)
int isKeyword(char str[])
{
    char keywords[][10] = {
        "int", "float", "char", "if", "else",
        "for", "while", "return", "void"};

    int total = 9;

    for (int i = 0; i < total; i++)
    {
        int j = 0;

        // compare each character
        while (str[j] == keywords[i][j] && str[j] != '\0')
        {
            j++;
        }

        // if both end at same time → match
        if (str[j] == '\0' && keywords[i][j] == '\0')
            return 1;
    }

    return 0;
}

int main()
{
    char str[100];
    int i = 0, ch;

    // Step 1: Take input
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[i++] = ch;
    }
    str[i] = '\0';

    // Step 2: Check empty input
    if (i == 0)
    {
        printf("Invalid Identifier\n");
        return 0;
    }

    // Step 3: First character check
    if (!(isLetter(str[0]) || str[0] == '_'))
    {
        printf("Invalid Identifier\n");
        return 0;
    }

    // Step 4: Check remaining characters
    for (int j = 1; str[j] != '\0'; j++)
    {
        if (!(isLetter(str[j]) || isDigit(str[j]) || str[j] == '_'))
        {
            printf("Invalid Identifier\n");
            return 0;
        }
    }

    // Step 5: Check keyword
    if (isKeyword(str))
    {
        printf("Invalid Identifier (Keyword)\n");
        return 0;
    }

    // Final result
    printf("Valid Identifier\n");

    return 0;
}