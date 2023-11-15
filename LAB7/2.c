#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the LCS and its length
void longest_common_subsequence(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);

    // Initialize a table to store the length of LCS
    int lcs_table[MAX_LENGTH][MAX_LENGTH];

    // Build the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                lcs_table[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            else
                lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
        }
    }

    // Find the LCS
    int index = lcs_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (lcs_table[i - 1][j] >= lcs_table[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS and its length
    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", lcs_table[m][n]);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    // Get input from the user
    printf("Enter the first string into an array: ");
    scanf("%s", str1);

    printf("Enter the second string into an array: ");
    scanf("%s", str2);

    // Find and print the LCS
    longest_common_subsequence(str1, str2);

    return 0;
}
