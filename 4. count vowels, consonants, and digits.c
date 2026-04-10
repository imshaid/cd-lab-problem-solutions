/*
Problem Statement:
Write a program that will count vowels, consonants, and digits.

--------------------------------------------------
Sample Test Cases:

Input: Hello123
Output:
Vowels: 2
Consonants: 3
Digits: 3

Input: Compiler Design Lab 2024
Output:
Vowels: 6
Consonants: 11
Digits: 4

Input: aeiou
Output:
Vowels: 5
Consonants: 0
Digits: 0

Input: 12345
Output:
Vowels: 0
Consonants: 0
Digits: 5
--------------------------------------------------

Explanation:
This program reads input character by character using getchar().

We use functions from <ctype.h>:
- isalpha() → checks if character is a letter
- isdigit() → checks if character is a digit

Logic:
- If digit → digit++
- Else if letter:
    - If vowel → vowel++
    - Else → consonant++

Note:
- Case insensitive (A, E, I, O, U also counted as vowels)
- Spaces and symbols are ignored
*/

#include <stdio.h>
#include <ctype.h> // for isalpha(), isdigit(), tolower()

int main()
{
    int ch;
    int vowels = 0, consonants = 0, digits = 0;

    // Read input character by character
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // Check digit
        if (isdigit(ch))
        {
            digits++;
        }
        // Check alphabet
        else if (isalpha(ch))
        {
            char lower = tolower(ch); // convert to lowercase

            // Check vowel
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        // Ignore other characters (space, symbols)
    }

    // Output results
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);

    return 0;
}