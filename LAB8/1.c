#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

// Queue implementation for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to perform BFS traversal and compute distances
void bfs(int graph[MAX_NODES][MAX_NODES], int n, int start, int distances[]) {
    bool visited[MAX_NODES];
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
        distances[i] = -1;
    }

    struct Queue* queue = createQueue(n);

    visited[start] = true;
    distances[start] = 0;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);

        for (int i = 1; i <= n; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
                distances[i] = distances[current] + 2;
            }
        }
    }

    free(queue->array);
    free(queue);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX_NODES][MAX_NODES] = {0};
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;  // Assuming undirected graph
    }

    int start;
    scanf("%d", &start);

    int distances[MAX_NODES];
    bfs(graph, n, start, distances);

    // Output BFS traversal
    printf("BFS Traversal:");
    for (int i = 1; i <= n; ++i) {
        if (distances[i] != -1) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Output distances
    // Output distances
printf("Distance: [");
for (int i = 1; i <= n; ++i) {
    if (distances[i] != -1) {
        printf("%d", distances[i]);
    } else {
        printf("-1");
    }
    if (i < n) {
        printf(" ");
    }
}
printf("]\n");

    return 0;
}

