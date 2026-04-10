/*
Problem Statement:
Write a C program to count the number of prepositions in a given string.

--------------------------------------------------
Sample Test Cases:

Input:
He is sitting on the chair in the room

Output:
Total Prepositions: 2

Input:
He went to school with his friend

Output:
Total Prepositions: 2

Input:
Hello world

Output:
Total Prepositions: 0

Input:
(empty input)

Output:
Total Prepositions: 0
--------------------------------------------------

Explanation:
This program counts how many prepositions exist in a given string.

Approach:
- Extract words manually
- Convert each word to lowercase
- Compare with predefined preposition list
- Count matches
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

    // list of common prepositions
    char prep[][20] = {
        "in", "on", "at", "to", "for", "with", "from",
        "by", "of", "under", "over", "between", "into", "onto"};

    int totalPrep = 14;
    int count = 0;

    // Step 2: Extract words
    i = 0;
    while (i <= len)
    {
        while (i <= len && line[i] == ' ')
            i++;

        if (i == len || line[i] == '\0')
            break;

        int start = i;

        while (i <= len && line[i] != ' ' && line[i] != '\0')
            i++;

        char lower[100];
        int k = 0;

        // copy word and convert to lowercase
        for (int j = start; j < i; j++)
        {
            lower[k++] = tolower(line[j]);
        }
        lower[k] = '\0';

        // Step 3: Check preposition
        for (int p = 0; p < totalPrep; p++)
        {
            if (strcmp(lower, prep[p]) == 0)
            {
                count++;
                break;
            }
        }
    }

    // Step 4: Output
    printf("Total Prepositions: %d\n", count);

    return 0;
}