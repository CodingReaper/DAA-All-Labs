#include <stdio.h>
#include<limits.h>
#include<stdlib.h>
#define ARRAY_SIZE 15

int countDuplicates(int arr[], int n) {
    int fr[n];    
    int visited = -1;    
    for(int i = 0; i < n; i++){    
        int count = 1;    
        for(int j = i+1; j < n; j++){    
            if(arr[i] == arr[j]){    
                count++;    
                fr[j] = visited;    
            }    
        }    
        if(fr[i] != visited){
             fr[i] = count;   
        }
    }
    int k =0;
    for(int i=0;i<n;i++){
        if(fr[i]>=2){
            k++;
        }
    }   
    return k;
}

int mostRepeatingElement(int arr[], int n) {
    int maxCount = 0;
    int mostRepeatedElement = arr[0];
    
    for (int i = 0; i < n; i++) {
        int count = 1; 
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeatedElement = arr[i];
        }
    }
    return mostRepeatedElement;
}

int main() {
    FILE *file;
    int arr[ARRAY_SIZE];
    int i = 0;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    while (i < ARRAY_SIZE && fscanf(file, "%d", &arr[i]) == 1) {
        i++;
    }
    fclose(file);
    printf("Numbers read from the file:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int size = sizeof(arr)/sizeof(int);
    int totalDuplicates = countDuplicates(arr, size);
    int mostRepeated = mostRepeatingElement(arr, size);
    printf("\nTotal number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeated);
    return 0;
}
