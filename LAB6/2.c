#include <stdio.h>
#include <stdlib.h>

// Define the SYMBOL structure
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define the HUFFMAN_NODE structure for the Huffman tree
struct HUFFMAN_NODE {
    char data;
    int frequency;
    struct HUFFMAN_NODE* left;
    struct HUFFMAN_NODE* right;
};

// Function to create a new HUFFMAN_NODE
struct HUFFMAN_NODE* createHuffmanNode(char data, int frequency) {
    struct HUFFMAN_NODE* newNode = (struct HUFFMAN_NODE*)malloc(sizeof(struct HUFFMAN_NODE));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a HUFFMAN_NODE into the min-priority queue
void insert(struct HUFFMAN_NODE* huffmanQueue[], int* size, struct HUFFMAN_NODE* node) {
    (*size)++;
    int i = (*size) - 1;

    while (i > 0 && node->frequency < huffmanQueue[(i - 1) / 2]->frequency) {
        huffmanQueue[i] = huffmanQueue[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    huffmanQueue[i] = node;
}

// Function to extract the minimum node from the min-priority queue
struct HUFFMAN_NODE* extractMin(struct HUFFMAN_NODE* huffmanQueue[], int* size) {
    struct HUFFMAN_NODE* minNode = huffmanQueue[0];
    huffmanQueue[0] = huffmanQueue[(*size) - 1];
    (*size)--;
    int i = 0;

    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < (*size) && huffmanQueue[leftChild]->frequency < huffmanQueue[i]->frequency)
            smallest = leftChild;
        if (rightChild < (*size) && huffmanQueue[rightChild]->frequency < huffmanQueue[smallest]->frequency)
            smallest = rightChild;

        if (smallest != i) {
            struct HUFFMAN_NODE* temp = huffmanQueue[i];
            huffmanQueue[i] = huffmanQueue[smallest];
            huffmanQueue[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }

    return minNode;
}

// Function to build the Huffman tree
struct HUFFMAN_NODE* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct HUFFMAN_NODE* huffmanQueue[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        huffmanQueue[i] = createHuffmanNode(symbols[i].alphabet, symbols[i].frequency);
        insert(huffmanQueue, &size, huffmanQueue[i]);
    }

    while (size > 1) {
        struct HUFFMAN_NODE* left = extractMin(huffmanQueue, &size);
        struct HUFFMAN_NODE* right = extractMin(huffmanQueue, &size);
        struct HUFFMAN_NODE* newNode = createHuffmanNode(' ', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        insert(huffmanQueue, &size, newNode);
    }

    return huffmanQueue[0];
}

// Function to perform in-order traversal of the Huffman tree
void inOrderTraversal(struct HUFFMAN_NODE* root) {
    if (root) {
        inOrderTraversal(root->left);
        if (root->data != ' ')
            printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];

    printf("Enter the alphabets:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet); // Use a space before %c to consume the newline character
    }

    printf("Enter its frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct HUFFMAN_NODE* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
