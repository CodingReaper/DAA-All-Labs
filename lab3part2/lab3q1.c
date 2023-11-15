#include <stdio.h>

int binary_search_leftmost(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int position = -1;
    int comparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target) {
            position = mid;
            right = mid - 1;//ignoring the right half
        } else if (arr[mid] < target) { //ignore left half
            left = mid + 1;
        } else {//ignore right half
            right = mid - 1;
        }
    }
    printf("Number of comparisons made: %d\n", comparisons);
    return position;
}

int main() {
    int arr[] = {2,3,7,7,7,11,12,12,20,50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int position = binary_search_leftmost(arr, n, target);
    if (position != -1) {
        printf("The leftmost appearance of %d is at position %d.\n", target, position);
    } else {
        printf("%d is not found in the array.\n", target);
    }
    return 0;
}
