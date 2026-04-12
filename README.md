# CSE314 — Compiler Design Lab | Problem Solutions

> **18 solved problems** covering string processing, lexical analysis, tokenization, DFA simulation, and NLP — each with full explanations, logic breakdown, and test cases. Built for lab final prep.

<br>

![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square) ![Problems](https://img.shields.io/badge/Problems-18%20Solved-success?style=flat-square) ![Topics](https://img.shields.io/badge/Topics-7%20Categories-orange?style=flat-square) ![Course](https://img.shields.io/badge/Course-CSE314-purple?style=flat-square)

---

## Quick Stats

| 18 Total Problems | 18 C Programs | 7 Topic Categories |
| :---------------: | :-----------: | :----------------: |

---

## All Problems

| #   | Problem                                            | Topic               |
| --- | -------------------------------------------------- | ------------------- |
| 01  | Count the length of a string                       | String Basics       |
| 02  | Count the number of white spaces                   | String Basics       |
| 03  | Remove white space from a string                   | String Basics       |
| 04  | Count vowels, consonants, and digits               | Char Classification |
| 05a | Tokenize a string (using `strtok()`)               | Tokenization        |
| 05b | Tokenize a string (without library function)       | Tokenization        |
| 06  | Count the number of lines                          | String Basics       |
| 07  | Identify the comments                              | Lexical Analysis    |
| 08  | Remove single-line or multi-line comments          | Lexical Analysis    |
| 09  | Max frequency of a word in a string                | Word Classification |
| 10  | Check if identifier is valid or not                | Lexical Analysis    |
| 11  | Count the articles                                 | Word Classification |
| 12  | Extract prepositions from a string                 | Word Classification |
| 13  | Count prepositions from a string                   | Word Classification |
| 14  | Check if RE `a*b` accepts the string               | Automata / DFA      |
| 15  | Extract the digits from a string                   | Char Classification |
| 16  | Generate the title of a paragraph                  | NLP                 |
| 17  | Extract conjunctions from a string                 | Word Classification |
| 18  | Sentiment analysis — Sad or Neutral                | NLP                 |

---

## Topic Breakdown

### String Basics — Problems 01, 02, 03, 06

Core string operations without any fancy library stuff. Reading character-by-character, counting, filtering whitespace, detecting newlines. This is the real foundation before anything compiler-related.

**Key concepts:** `getchar()` · `isspace()` · EOF handling · char-by-char traversal

---

### Character Classification — Problems 04, 15

Classifying each character as vowel, consonant, digit, or symbol. Looks simple on the surface — shows up in every real lexer.

**Key concepts:** vowel/consonant check · digit range check · char-by-char classification

---

### Tokenization — Problems 05a, 05b

Two approaches to the same problem. 05a uses `strtok()` from the library. 05b does it **from scratch** — no library functions, just raw character scanning. Building a tokenizer manually is the core skill behind writing an actual Lexer.

**Key concepts:** `strtok()` · manual delimiter scanning · token counting

---

### Lexical Analysis — Problems 07, 08, 10

The real compiler stuff. These simulate exactly what a Lexer does:

- **Problem 07** — identifies `//` single-line and `/* */` multi-line comments
- **Problem 08** — removes those comments from source code, outputs clean code
- **Problem 10** — validates C identifiers: checks first character, remaining characters, and matches against a keyword list

**Key concepts:** state tracking · character lookahead · keyword matching · identifier rules

---

### Word Classification — Problems 09, 11, 12, 13, 17

Extracting and counting specific word types from natural language — articles (`a`, `an`, `the`), prepositions (`in`, `on`, `at`...), conjunctions (`and`, `or`, `but`...) — plus finding the most frequent word using manual word extraction.

**Key concepts:** predefined word lists · frequency counting · manual tokenization · string comparison

---

### Automata / DFA — Problem 14

Simulates a **Deterministic Finite Automaton** in C to check if input matches the Regular Expression `a*b` (zero or more `a` followed by exactly one `b`). This is where automata theory meets actual code.

**Key concepts:** DFA simulation · RE matching · state transitions

---

### NLP — Problems 16, 18

Higher-level problems implemented in C from pseudocode:

- **Problem 16** — generates a paragraph title by finding the most frequent meaningful word after removing stop words
- **Problem 18** — classifies text as **Sad** or **Neutral** using a predefined word list and a percentage-based threshold (≥20% sad words → SAD)

**Key concepts:** stop word removal · frequency-based title generation · sentiment scoring · threshold classification

---

## Compile & Run

```bash
# Step 1: Compile
gcc -o out "01. count the length of a string.c"

# Step 2: Run
./out

# Example output:
# Hello World
# Length of the string: 11
```

> **Note:** Every `.c` file has the full problem statement, explanation, and test cases written inside the comments. Open the file first, read it, then run.

### Input Notes

| Problem                   | How to stop input                                  |
| ------------------------- | -------------------------------------------------- |
| 06 (line counter)         | Press Enter on an empty line                       |
| 07, 08 (comment problems) | Press Enter on an empty line                       |
| 14 (DFA)                  | Try `aaab`, `b`, `aabbb`, `abc` to test all states |

---

## Tech Stack

| Tool     | Version          |
| -------- | ---------------- |
| Language | C (C99 standard) |
| Compiler | GCC              |
| Platform | Windows          |
| IDE      | VS Code          |

---

## Repository Structure

```
cd-lab-problem-solutions/
│
├── 01. count the length of a string.c
├── 02. count the number of white spaces from a string.c
├── 03. remove white space from a string.c
├── 04. count vowels, consonants, and digits.c
├── 05a. tokenize a string (using strtok()).c
├── 05b. tokenize a string (without library function).c
├── 06. count the number of lines.c
├── 07. identify the comments.c
├── 08. remove the single line or multiple line comments.c
├── 09. max frequency of a word in a string.c
├── 10.  identifier is valid or not.c
├── 11. count the articles.c
├── 12. extract preposition from a given string.c
├── 13. count preposition from a given string.c
├── 14. check the RE is accepted or not.c
├── 15. extract the digits from a string.c
├── 16. generate the title of a paragraph.c
├── 17. extract conjunctions from a given string.c
├── 18. analyze a paragraph and decide the sentiment between 2 classes as Sad or Neutral from a given wordlist.c
└── README.md
```

---

## Author

**Shaid (~sURJO)**  
CSE314 — Compiler Design Lab  
Department of Computer Science & Engineering
Daffodil International University, Dhaka

---

> ⭐ If this repo helped you prepare for your lab final, consider giving it a star!