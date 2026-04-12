/*
Problem Statement:
Write a C program that analyzes a paragraph and determines
whether the sentiment is SAD or NEUTRAL using a wordlist.

--------------------------------------------------
Sample Test Cases:

Input:
I feel so alone and lost in the dark. The pain is unbearable and I cry every night.

Output:
Total words         : 18
Sad words found     : 5
Sad score           : 27.8%
Matched sad words   : alone, lost, dark, pain, cry
Sentiment           : SAD

Input:
I went to the market today and bought some vegetables for dinner.

Output:
Total words         : 12
Sad words found     : 0
Sad score           : 0.0%
Matched sad words   : none
Sentiment           : NEUTRAL

Input:
I feel tired and a little down today but life goes on.

Output:
Total words         : 12
Sad words found     : 2
Sad score           : 16.7%
Matched sad words   : tired, down
Sentiment           : NEUTRAL

Input:


Output:
Total words         : 18
Sad words found     : 5
Sad score           : 27.7%
Matched sad words   : alone, lost, dark, pain, cry
Sentiment           : SAD
--------------------------------------------------

Explanation:
- Count total words
- Match sad words from list
- Calculate percentage
- If >= 20% → SAD, else NEUTRAL
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
        printf("No input given.\n");
        return 0;
    }

    // Sad word list
    char sad[][20] = {
        "sad", "cry", "tears", "grief", "alone", "lost", "pain", "hurt",
        "broken", "miss", "lonely", "empty", "dark", "hopeless", "sorrow",
        "suffer", "regret", "despair", "tired", "weak", "fail", "down",
        "gloomy", "mourn", "depressed", "miserable", "worthless",
        "abandoned", "heartbroken", "unfortunate", "unhappy", "melancholy"};

    int sadTotal = 32;

    char words[200][50];
    int total = 0;

    // Extract words (clean + lowercase)
    for (i = 0; line[i];)
    {
        while (line[i] == ' ')
            i++;

        int j = 0;
        while (isalnum(line[i]))
            words[total][j++] = tolower(line[i++]);

        words[total][j] = '\0';
        if (j > 0)
            total++;

        while (line[i] && !isalnum(line[i]))
            i++;
    }

    int sadCount = 0;
    char matched[200][50];
    int mCount = 0;

    // Match sad words
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < sadTotal; j++)
        {
            if (strcmp(words[i], sad[j]) == 0)
            {
                sadCount++;
                strcpy(matched[mCount++], words[i]);
                break;
            }
        }
    }

    // Calculate percentage
    float score = 0;
    if (total > 0)
        score = (sadCount * 100.0) / total;

    // Output
    printf("Total words         : %d\n", total);
    printf("Sad words found     : %d\n", sadCount);
    printf("Sad score           : %.1f%%\n", score);

    printf("Matched sad words   : ");
    if (mCount == 0)
        printf("none");
    else
    {
        for (int i = 0; i < mCount; i++)
        {
            printf("%s", matched[i]);
            if (i != mCount - 1)
                printf(", ");
        }
    }

    printf("\n");

    if (score >= 20)
        printf("Sentiment           : SAD\n");
    else
        printf("Sentiment           : NEUTRAL\n");

    return 0;
}