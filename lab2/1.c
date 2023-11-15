#include <stdio.h>
#include<stdlib.h>
void decimalToBinary(int num, int digits, FILE *outFile) {
    if (digits == 16) {
        return;
    }

    decimalToBinary(num >> 1, digits + 1, outFile);
    fprintf(outFile, "%d", (num & 1));
}

void printFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file: %s\n", filename);
        return;
    }
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
}

int main(int argc,char *argv[]) {
    FILE *inputFile, *outputFile;
    int num;
    int n = atoi(argv[1]);
    inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }
    outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return 1;
    }
    printf("Writing binary equivalents of the first %d numbers from the file to 'output.txt'...\n", n);
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &num) == 1) {
            fprintf(outputFile, "Binary of %d is: ", num);
            decimalToBinary(num, 0, outputFile);
            fprintf(outputFile, "\n");
        } else {
            printf("Error reading the numbers from the file.\n");
            break;
        }
    }
    printf("Binary equivalents have been stored in 'output.txt'.\n\n");
    fclose(inputFile);fclose(outputFile);
    printFileContents("output.txt");
    return 0;
}



