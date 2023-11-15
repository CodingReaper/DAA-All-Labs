#include <stdio.h>
#include <stdlib.h>

struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void heapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(struct ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct ITEM items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    heapSort(items, n);
    float knapsack_capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &knapsack_capacity);
    float max_profit = 0.0;
    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");
    for (int i = n - 1; i >= 0; i--) {
        if (knapsack_capacity >= items[i].item_weight) {
            printf("%d\t%.2f\t%.2f\t%.2f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].item_weight);
            max_profit += items[i].item_profit;
            knapsack_capacity -= items[i].item_weight;
        } else {
            float amount_taken = knapsack_capacity / items[i].item_weight;
            printf("%d\t%.2f\t%.2f\t%.2f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, amount_taken);
            max_profit += amount_taken * items[i].item_profit;
            break;
        }
    }
    printf("\nMaximum profit: %.6f\n", max_profit);
    return 0;
}