/*
Problem Statement:
Write a C program that will count and show the maximum frequency of a word in a string.

--------------------------------------------------
Sample Test Cases:

Input:
this is a test this is only a test

Output:
--- Word Frequency ---
this                 : 2  <-- MAX
is                   : 2  <-- MAX
a                    : 2  <-- MAX
test                 : 2  <-- MAX
only                 : 1

--- Highest Frequency : 2 ---
  "this"
  "is"
  "a"
  "test"

Input:
apple banana apple orange banana apple

Output:
--- Word Frequency ---
apple                : 3  <-- MAX
banana               : 2
orange               : 1

--- Highest Frequency : 3 ---
  "apple"

Input:
one two three four

Output:
--- Word Frequency ---
one                  : 1  <-- MAX
two                  : 1  <-- MAX
three                : 1  <-- MAX
four                 : 1  <-- MAX

--- Highest Frequency : 1 ---
  "one"
  "two"
  "three"
  "four"

Input:
(empty input)

Output:
--- Word Frequency ---

--- Highest Frequency : 0 ---
--------------------------------------------------

Explanation:
This program finds the frequency of each word in a string and identifies
the word(s) with the highest frequency.

Core Approach:
1. Read input character-by-character using getchar()
2. Manually extract words (without using strtok)
3. Maintain a list of unique words
4. Count occurrences of each word
5. Determine and display maximum frequency words

Key Learning:
- Manual tokenization (important in Compiler Design)
- String comparison without library functions
- Frequency counting logic
*/

#include <stdio.h>

int main()
{
    char line[1000]; // stores the full input line
    int i = 0, ch;

    // Step 1: Read input character-by-character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        line[i] = ch;
        i++;
    }
    line[i] = '\0'; // terminate string

    int len = i; // length of input

    // Storage for unique words and their frequencies
    char words[100][100]; // stores up to 100 unique words
    int freq[100];        // stores frequency of each word
    int wordCount = 0;    // number of unique words found

    // Step 2: Manual Tokenization + Frequency Counting
    i = 0;
    while (i <= len)
    {
        // Skip leading spaces
        while (i <= len && line[i] == ' ')
            i++;

        // Stop if end of string reached
        if (i == len || line[i] == '\0')
            break;

        // Mark starting index of word
        int start = i;

        // Move until end of word
        while (i <= len && line[i] != ' ' && line[i] != '\0')
            i++;


        // Extract the word into a temporary buffer

        char word[100];
        int wLen = 0;

        for (int k = start; k < i; k++)
            word[wLen++] = line[k];

        word[wLen] = '\0'; // terminate word


        // Step 3: Check if word already exists

        int found = 0;

        for (int j = 0; j < wordCount; j++)
        {
            int match = 1; // assume match

            int m = 0;
            // Manual string comparison (character-by-character)
            while (words[j][m] != '\0' || word[m] != '\0')
            {
                if (words[j][m] != word[m])
                {
                    match = 0;
                    break;
                }
                m++;
            }

            // If match found → increase frequency
            if (match)
            {
                freq[j]++;
                found = 1;
                break;
            }
        }


        // Step 4: If new word → store it

        if (!found)
        {
            int m = 0;
            while (word[m] != '\0')
            {
                words[wordCount][m] = word[m];
                m++;
            }
            words[wordCount][m] = '\0';

            freq[wordCount] = 1; // first occurrence
            wordCount++;
        }
    }

    // Step 5: Find maximum frequency
    int maxFreq = 0;

    for (int j = 0; j < wordCount; j++)
    {
        if (freq[j] > maxFreq)
            maxFreq = freq[j];
    }

    // Step 6: Display all word frequencies
    printf("--- Word Frequency ---\n");

    for (int j = 0; j < wordCount; j++)
    {
        printf("%-20s : %d", words[j], freq[j]);

        // Highlight max frequency words
        if (freq[j] == maxFreq)
            printf("  <-- MAX");

        printf("\n");
    }

    // Step 7: Display words with highest frequency
    printf("\n--- Highest Frequency : %d ---\n", maxFreq);

    for (int j = 0; j < wordCount; j++)
    {
        if (freq[j] == maxFreq)
            printf("  \"%s\"\n", words[j]);
    }

    return 0;
}