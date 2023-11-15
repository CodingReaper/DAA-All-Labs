#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, int *comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        
        merge(arr, l, m, r, comparisons);
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
        printf("MAIN MENU (MERGE SORT)\n");
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
        mergeSort(elements, 0, n - 1, &comparisons);
        clock_t end_time = clock();
        
        double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1e9;

        char outFileName[20];
        if (option == 1) {
            sprintf(outFileName, "outMergeAsce.txt");
        } else if (option == 2) {
            sprintf(outFileName, "outMergeDesc.txt");
        } else {
            sprintf(outFileName, "outMergeRand.txt");
        }
        
        write_output_file(outFileName, elements, n);

        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", elements[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);
        printf("Execution Time: %.2f nanoseconds\n", execution_time);
    }

    return 0;
}
