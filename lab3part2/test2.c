#include <stdio.h>
#include<stdlib.h>
int generate_random(int min, int max) {
    return min + (rand() % ((max - min + 1) / 10)) * 10;
}
void generateMultiplesOf10DescendingToFile(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = count; i >= 1; i--) {
        fprintf(file, "%d\n", i * 10);
    }

    fclose(file);
    printf("Multiples of 10 in descending order written to %s.\n", filename);
}

int main() {
    int count;
    char filename[100];

    count = generate_random(300,500);
    printf("Enter the filename to store the multiples: ");
    scanf("%s", filename);

    generateMultiplesOf10DescendingToFile(count, filename);

    return 0;
}
