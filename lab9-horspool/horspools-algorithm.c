#include <stdio.h>
#include <string.h>

#define MAX 500

int horspool(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int shiftTable[256];
    int i, j, k, comparisons = 0;

    for (i = 0; i < 256; i++) {
        shiftTable[i] = patternLen;
    }

    for (i = 0; i < patternLen - 1; i++) {
        shiftTable[pattern[i]] = patternLen - 1 - i;
    }

    i = patternLen - 1;
    while (i < textLen) {
        k = i;
        j = patternLen - 1;

        while (j >= 0 && text[k] == pattern[j]) {
            comparisons++;
            k--;
            j--;
        }

        if (j == -1) {
            return comparisons;
        } else {
            comparisons++;
            i += shiftTable[text[i]];
        }
    }

    return comparisons;
}

int main() {
    char text[MAX], pattern[MAX];
    int successComparisons, failureComparisons;

    printf("Enter the text: ");
    fgets(text, MAX, stdin);
    printf("Enter the pattern to search: ");
    fgets(pattern, MAX, stdin);

    // Removing newline characters from input
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    successComparisons = horspool(text, pattern);
    failureComparisons = horspool(text, "nonexistent");

    printf("Number of key comparisons in successful search: %d\n", successComparisons);
    printf("Number of key comparisons in unsuccessful search: %d\n", failureComparisons);

    return 0;
}

/*
sample input
Enter the text: This is a sample text for testing Horspool's algorithm.
Enter the pattern to search: sample
*/