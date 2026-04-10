/*
Problem Statement:
Write a C program that will identify the articles from a given input string
and count the articles.

--------------------------------------------------
Sample Test Cases:

Input:
This is a test of the system

Output:
Articles found:
a
the
Total Articles: 2

Input:
An apple a day keeps the doctor away

Output:
Articles found:
An
a
the
Total Articles: 3

Input:
Hello world

Output:
No Articles Found

Input:
(empty input)

Output:
No Articles Found
--------------------------------------------------

Explanation:
This program finds articles (a, an, the) from a given string.

Steps:
1. Take input using getchar()
2. Extract words manually (without strtok)
3. Check each word:
   - if it is "a", "an", or "the"
4. Print found articles and count them

Note:
- Case-insensitive (A, An, THE should also be counted)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char line[1000];
    int i = 0, ch;

    // Step 1: Input
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        line[i++] = ch;
    }
    line[i] = '\0';

    int len = i;

    char found[100][100]; // store found articles
    int count = 0;

    // Step 2: Extract words
    i = 0;
    while (i <= len)
    {
        // skip spaces
        while (i <= len && line[i] == ' ')
            i++;

        if (i == len || line[i] == '\0')
            break;

        int start = i;

        // find end of word
        while (i <= len && line[i] != ' ' && line[i] != '\0')
            i++;

        char word[100], lower[100];
        int k = 0;

        // copy word
        for (int j = start; j < i; j++)
        {
            word[k] = line[j];
            lower[k] = tolower(line[j]); // convert to lowercase
            k++;
        }
        word[k] = '\0';
        lower[k] = '\0';

        // Step 3: Check article
        if (strcmp(lower, "a") == 0 ||
            strcmp(lower, "an") == 0 ||
            strcmp(lower, "the") == 0)
        {
            strcpy(found[count], word); // store original word
            count++;
        }
    }

    // Step 4: Output
    if (count == 0)
    {
        printf("No Articles Found\n");
    }
    else
    {
        printf("Articles found:\n");

        for (int i = 0; i < count; i++)
        {
            printf("%s\n", found[i]);
        }

        printf("Total Articles: %d\n", count);
    }

    return 0;
}