#include <stdio.h>
#include<limits.h>
#include<stdlib.h>
#define ARRAY_SIZE 5
int findSecondSmallest(int arr[], int size) {
    if (size < 2) {
        printf("Array size must be at least 2 to find the second smallest element.\n");
        return -1; 
    }
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    if (secondSmallest == INT_MAX) {
        printf("There is no second smallest element in the array.\n");
        return -1; 
    }
    return secondSmallest;
}
int findSecondLargest(int arr[], int size) {
    if (size < 2) {
        printf("Array size must be at least 2 to find the second largest element.\n");
        return -1;
    }
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    if (secondLargest == INT_MIN) {
        printf("There is no second largest element in the array.\n");
        return -1; 
    }
    return secondLargest;
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
    int seclarge = findSecondLargest(arr,size);
    int secsmall = findSecondSmallest(arr,size);
    int j = 0;
    int newsize = size-2;
    int arr2[newsize];
    for(int i=0;i<size;i++){
        if(arr[i] != seclarge && arr[i] != secsmall){
            arr2[j++] = arr[i];
        }
    }
    printf("Second Largest:%d\n",seclarge);
    printf("Second Smallest:%d\n",secsmall);
    printf("Remaining Array:");
    for(int i=0;i<newsize;i++){
        printf("%d  ",arr2[i]);
    }
    printf("\n");
    return 0;
}

