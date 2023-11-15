#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void read_input_file(const char *file_name, int arr[], int *n) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }
    int num;
    *n = 0;
    while (fscanf(file, "%d", &num) != EOF) {
        arr[(*n)++] = num;
    }
    fclose(file);
}

void write_output_file(const char *file_name, int arr[], int n) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n ", arr[i]);
    }
    fclose(file);
}

int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void generateMultiplesOf10ToFile(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 1; i <= count; i++) {
        fprintf(file, "%d\n", i * 10);
    }
    fclose(file);
    printf("Multiples of 10 written to %s.Count:%d\n", filename,count);
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
    printf("Multiples of 10 in descending order written to %s.Count:%d\n", filename,count);
}

void generateRandomMultiplesOf11ToFile(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
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
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", multiples[i]);
    }
    free(multiples);
    fclose(file);
    printf("Random multiples of 11 written to %s.\n", filename);
}


int main() {
    int option;
    int elements[500]; 
    int n;
    int comparisons;
    int count;
    count = generateRandomNumber(300,500);
    generateMultiplesOf10ToFile(count, "inAsce.txt");
    generateMultiplesOf10DescendingToFile(count, "inDesc.txt");
    generateRandomMultiplesOf11ToFile(count, "inRand.txt");
    while (1) {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 1) {
            read_input_file("inAsce.txt", elements, &n);
        } else if (option == 2) {
            read_input_file("inDesc.txt", elements, &n);
        } else if (option == 3) {
            read_input_file("inRand.txt", elements, &n);
        } else if (option == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option. Please choose a valid option.\n");
            continue;
        }
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", elements[i]);
        }
        printf("\n");
        comparisons = 0;
        insertion_sort(elements, n, &comparisons);
        write_output_file("outIns.dat", elements, n);
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", elements[i]);
        }
        printf("\n");
        printf("Number of Comparisons: %d\n", comparisons);
        if (comparisons == 0) {
            printf("Scenario: Best-case\n");
        } else if (comparisons >= n * (n - 1) / 2) {
            printf("Scenario: Worst-case\n");
        } else {
            printf("Scenario: Average-case\n");
        }
    }
    return 0;
}
