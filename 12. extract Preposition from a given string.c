/*
Problem Statement:
Write a C program that will extract prepositions from a given string.

--------------------------------------------------
Sample Test Cases:

Input:
He is sitting on the chair in the room

Output:
Prepositions found:
on
in
Total Prepositions: 2

Input:
She went to school with her friend

Output:
Prepositions found:
to
with
Total Prepositions: 2

Input:
Hello world

Output:
No Prepositions Found

Input:
(empty input)

Output:
No Prepositions Found
--------------------------------------------------

Explanation:
This program extracts prepositions from a string.

Approach:
- Extract words manually
- Convert word to lowercase
- Compare with a predefined list of prepositions
- Store and print them
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

    char found[100][100];
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

        char word[100], lower[100];
        int k = 0;

        // copy word + convert to lowercase
        for (int j = start; j < i; j++)
        {
            word[k] = line[j];
            lower[k] = tolower(line[j]);
            k++;
        }
        word[k] = '\0';
        lower[k] = '\0';

        // Step 3: Check preposition
        for (int p = 0; p < totalPrep; p++)
        {
            if (strcmp(lower, prep[p]) == 0)
            {
                strcpy(found[count], word); // store original word
                count++;
                break;
            }
        }
    }

    // Step 4: Output
    if (count == 0)
    {
        printf("No Prepositions Found\n");
    }
    else
    {
        printf("Prepositions found:\n");

        for (int i = 0; i < count; i++)
        {
            printf("%s\n", found[i]);
        }

        printf("Total Prepositions: %d\n", count);
    }

    return 0;
}