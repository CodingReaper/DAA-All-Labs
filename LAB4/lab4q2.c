#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
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
        fprintf(file, "%d\n", arr[i]);
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
    printf("Multiples of 10 written to %s. Count: %d\n", filename, count);
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
    printf("Multiples of 10 in descending order written to %s. Count: %d\n", filename, count);
}

void generateRandomMultiplesOf11ToFile(int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", generateRandomNumber(0, 100) * 11);
    }
    fclose(file);
    printf("Random multiples of 11 written to %s.\n", filename);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int option;
    int elements[500];
    int n;
    int comparisons;
    int count;

    // count = generateRandomNumber(300, 500);
    // generateMultiplesOf10ToFile(count, "inAsce.txt");
    // generateMultiplesOf10DescendingToFile(count, "inDesc.txt");
    // generateRandomMultiplesOf11ToFile(count, "inRand.txt");

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
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
        clock_t start_time = clock();
        quickSort(elements, 0, n - 1, &comparisons);
        clock_t end_time = clock();
        
        double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1e9;

        char outFileName[20];
        if (option == 1) {
            sprintf(outFileName, "outQuickAsce.txt");
        } else if (option == 2) {
            sprintf(outFileName, "outQuickDesc.txt");
        } else {
            sprintf(outFileName, "outQuickRand.txt");
        }
        
        write_output_file(outFileName, elements, n);

        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", elements[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);
        
        if (comparisons == n - 1) {
            printf("Scenario: Best-case partitioning\n");
        } else if (comparisons == (n * (n - 1)) / 2) {
            printf("Scenario: Worst-case partitioning\n");
        } else {
            printf("Scenario: Average-case partitioning\n");
        }
    }

    return 0;
}
