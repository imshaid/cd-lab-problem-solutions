/*
Problem Statement:
Write a C program to generate the title of a paragraph.

--------------------------------------------------
Sample Test Case:

Input:
The dog chased the cat. The dog was very fast. The cat ran away quickly.

Output:
Generated Title: Dog

Input:
I love C programming. C is a great language.

Output:
Generated Title: C

Input:
The the the the

Output:
Generated Title: the

Input:
(empty)

Output:
No title can be generated.
--------------------------------------------------

Explanation:
This program generates a title from a paragraph by finding
the most frequent meaningful word.

Steps:
1. Take input paragraph
2. Convert all words to lowercase and remove punctuation
3. Remove stop words (a, an, the, etc.)
4. Count frequency of remaining words
5. Select the word with highest frequency
6. Capitalize first letter and print as title

Note:
- If multiple words have same frequency, first one is selected
- If no meaningful word found, first word is used as fallback
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char line[1000];
    int i = 0, ch;

    // Input
    while ((ch = getchar()) != '\n' && ch != EOF)
        line[i++] = ch;
    line[i] = '\0';

    if (i == 0)
    {
        printf("No title can be generated.\n");
        return 0;
    }

    // Stop words
    char stop[][10] = {"a", "an", "the", "is", "are", "was", "and", "or", "in", "on", "at", "to", "of"};
    int stopCount = 13;

    char words[100][50];
    int count = 0;

    // Extract words
    for (i = 0; line[i];)
    {
        while (line[i] == ' ')
            i++;

        int j = 0;
        while (isalnum(line[i]))
            words[count][j++] = tolower(line[i++]);

        words[count][j] = '\0';
        if (j > 0)
            count++;

        while (line[i] && !isalnum(line[i]))
            i++;
    }

    // Frequency
    char unique[100][50];
    int freq[100], uCount = 0;

    for (int i = 0; i < count; i++)
    {
        int isStop = 0;
        for (int j = 0; j < stopCount; j++)
            if (strcmp(words[i], stop[j]) == 0)
                isStop = 1;

        if (isStop)
            continue;

        int found = 0;
        for (int j = 0; j < uCount; j++)
        {
            if (strcmp(unique[j], words[i]) == 0)
            {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            strcpy(unique[uCount], words[i]);
            freq[uCount++] = 1;
        }
    }

    // Find max
    int max = 0, index = -1;
    for (int i = 0; i < uCount; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            index = i;
        }
    }

    // Fallback
    if (index == -1)
        strcpy(unique[0], words[0]);
    else
        unique[0][0] = toupper(unique[index][0]);

    printf("Generated Title: %s\n", unique[0]);

    return 0;
}