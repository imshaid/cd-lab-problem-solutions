/*
Problem Statement:
Write a C program that will extract conjunctions from a given string.

--------------------------------------------------
Sample Test Cases:

Input:
He is poor but honest

Output:
Conjunctions found:
but
Total Conjunctions: 1

Input:
I will go if you come and stay

Output:
Conjunctions found:
if
and
Total Conjunctions: 2

Input:
Hello world

Output:
No Conjunctions Found

Input:
(empty input)

Output:
No Conjunctions Found
--------------------------------------------------

Explanation:
This program extracts conjunctions from a string.

Approach:
- Extract words manually
- Convert word to lowercase
- Compare with a predefined list of conjunctions
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

    // list of common conjunctions
    char conj[][20] = {
        "and", "or", "but", "so", "yet", "for",
        "nor", "although", "because", "if", "while"};

    int totalConj = 11;

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

        // Step 3: Check conjunction
        for (int p = 0; p < totalConj; p++)
        {
            if (strcmp(lower, conj[p]) == 0)
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
        printf("No Conjunctions Found\n");
    }
    else
    {
        printf("Conjunctions found:\n");

        for (int i = 0; i < count; i++)
        {
            printf("%s\n", found[i]);
        }

        printf("Total Conjunctions: %d\n", count);
    }

    return 0;
}