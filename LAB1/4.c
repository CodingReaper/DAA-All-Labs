#include <stdio.h>
void EXCHANGE(int arr[], int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}
void ROTATE_RIGHT(int arr[], int size, int p2) {
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(arr, i, i - 1);
    }
}
int main() {
    int N = 9;
    int A[9];
    printf("Enter an array A of size N (%d): ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    ROTATE_RIGHT(A, N, 5);
    printf("Before ROTATE:\t");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }
    return 0;
}
