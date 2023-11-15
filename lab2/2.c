#include<stdio.h>

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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc,char * argv[]) {
    FILE *inputFile, *outputFile;
    int num1, num2, result;

    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    while (fscanf(inputFile, "%d", &num1) == 1 && fscanf(inputFile, "%d", &num2) == 1) {
        result = gcd(num1, num2);
        fprintf(outputFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("GCD calculations completed and results stored in output.txt.\n");

    return 0;
}