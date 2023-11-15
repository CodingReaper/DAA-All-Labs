#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addEdge(struct Node* adjacencyList[], int src, int dest, int degrees[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;

    // Increment the degrees of the source and destination nodes
    degrees[src]++;
    degrees[dest]++;
}

void printGraph(struct Node* adjacencyList[], int n, int degrees[]) {
    for (int i = 0; i < n; i++) {
        struct Node* currentNode = adjacencyList[i];
        printf("Node %d: Degree %d, Adjacent vertices: ", i, degrees[i]);
        while (currentNode) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m; // Number of nodes and edges5
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    struct Node* adjacencyList[n];
    for (int i = 0; i < n; i++) {
        adjacencyList[i] = NULL;
    }

    int degrees[n]; // Array to store degrees of nodes, initialized to 0
    for (int i = 0; i < n; i++) {
        degrees[i] = 0;
    }

    printf("Enter the edges in the format 'src dest':\n");
    for (int i = 0; i < m; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjacencyList, src, dest, degrees);
    }

    // Print the adjacency list and the degree of each node
    printGraph(adjacencyList, n, degrees);

    return 0;
}
