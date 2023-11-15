#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomMultiplesOf11ToFile(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    srand(time(NULL));
    int *multiples = malloc(count * sizeof(int));
    if (multiples == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        return;
    }
    for (int i = 0; i < count; i++) {
        multiples[i] = (rand() % 100) * 11;
    }
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = multiples[i];
        multiples[i] = multiples[j];
        multiples[j] = temp;
    }
    fprintf(file, "Random multiples of 11:\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", multiples[i]);
    }
    free(multiples);
    fclose(file);
    printf("Random multiples of 11 written to %s.\n", filename);
}

int main() {
    int count;
    char filename[100];

    printf("Enter the number of random multiples of 11 you want to generate: ");
    scanf("%d", &count);

    printf("Enter the filename to store the random multiples: ");
    scanf("%s", filename);

    generateRandomMultiplesOf11ToFile(count, filename);

    return 0;
}
