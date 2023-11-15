// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct person
// {
//     int id;
//     char *name;
//     int age;
//     int height;
//     int weight;
// };

// struct person *heap;
// int heapSize = 0;

// void swap(struct person *a, struct person *b)
// {
//     struct person temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapifyDown(int index)
// {
//     int smallest = index;
//     int leftChild = 2 * index + 1;
//     int rightChild = 2 * index + 2;

//     if (leftChild < heapSize && heap[leftChild].age < heap[smallest].age)
//         smallest = leftChild;

//     if (rightChild < heapSize && heap[rightChild].age < heap[smallest].age)
//         smallest = rightChild;

//     if (smallest != index)
//     {
//         swap(&heap[index], &heap[smallest]);
//         heapifyDown(smallest);
//     }
// }

// void heapifyUp(int index)
// {
//     int parent = (index - 1) / 2;
//     while (index > 0 && heap[index].age < heap[parent].age)
//     {
//         swap(&heap[index], &heap[parent]);
//         index = parent;
//         parent = (index - 1) / 2;
//     }
// }

// void insertPerson(struct person p)
// {
//     heapSize++;
//     heap = (struct person *)realloc(heap, heapSize * sizeof(struct person));
//     heap[heapSize - 1] = p;
//     heapifyUp(heapSize - 1);
// }

// void deleteMin()
// {
//     if (heapSize == 0)
//     {
//         printf("Heap is empty.\n");
//         return;
//     }

//     heap[0] = heap[heapSize - 1];
//     heapSize--;
//     heapifyDown(0);

//     printf("Oldest person deleted from Min-Heap.\n");
// }

// void displayHeap()
// {
//     printf("Id\tName\t\tAge\tHeight\tWeight(pound)\n");
//     for (int i = 0; i < heapSize; i++)
//     {
//         printf("%d\t%s\t%d\t%d\t%d\n", heap[i].id, heap[i].name, heap[i].age, heap[i].height, heap[i].weight);
//     }
// }

// int readDataFromFile(const char *filename)
// {
//     FILE *file = fopen(filename, "r");

//     if (file == NULL)
//     {
//         printf("Error opening the file.\n");
//         return 0;
//     }

//     int n;
//     fscanf(file, "%d", &n);

//     heap = (struct person *)malloc(n * sizeof(struct person));
//     if (heap == NULL)
//     {
//         printf("Memory allocation error.\n");
//         fclose(file);
//         return 0;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         heap[i].name = (char *)malloc(100 * sizeof(char)); // Adjust size as needed
//         if (heap[i].name == NULL)
//         {
//             printf("Memory allocation error.\n");
//             fclose(file);
//             for (int j = 0; j < i; j++)
//             {
//                 free(heap[j].name);
//             }
//             free(heap);
//             return 0;
//         }

//         fscanf(file, "%d %s %d %d %d", &heap[i].id, heap[i].name, &heap[i].age, &heap[i].height, &heap[i].weight);
//         heapSize++;
//     }

//     fclose(file);

//     // Print the data
//     printf("Data read from the file:\n");
//     displayHeap();

//     return 1;
// }

// int main()
// {
//     int option;
//     do
//     {
//         printf("\nMAIN MENU (HEAP)\n");
//         printf("1. Read Data\n");
//         printf("2. Create a Min-heap based on the age also display it\n");
//         printf("3. Create a Max-heap based on the weight also display it\n");
//         printf("4. Display weight of the youngest person\n");
//         printf("5. Insert a new person into the Min-heap\n");
//         printf("6. Delete the oldest person\n");
//         printf("7. Exit\n");
//         printf("Enter option: ");
//         scanf("%d", &option);

//         switch (option)
//         {
//             case 1:
//             {
//                 char filename[100];
//                 printf("Enter the filename: ");
//                 scanf("%s", filename);
//                 if (readDataFromFile(filename))
//                 {
//                     printf("Data read from the file and stored in the array.\n");
//                 }
//                 break;
//             }
//             case 2:
//                 // Create a Min-heap based on the age and display it
//                 for (int i = heapSize / 2 - 1; i >= 0; i--)
//                 {
//                     heapifyDown(i);
//                 }
//                 printf("Min-Heap based on Age:\n");
//                 displayHeap();
//                 break;
//             case 3:
//                 // Create a Max-heap based on the weight and display it
//                 for (int i = heapSize / 2 - 1; i >= 0; i--)
//                 {
//                     heapifyDown(i);
//                 }
//                 printf("Max-Heap based on Weight:\n");
//                 displayHeap();
//                 break;
//             case 4:
//             {
//                 if(heapSize>0){
//                     int youngestIndex = 0;
//                     for(int i=1;i<heapSize;i++){
//                         if (heap[i].age < heap[youngestIndex].age){
//                             youngestIndex = i;
//                         }

//                     }
//                     printf("Weight of the youngest person (age %d): %d pounds\n", heap[youngestIndex].age, heap[youngestIndex].weight);
//                 }
//                 else{
//                      printf("No data available.\n");
//                 }
//                 break;
//             }
//             case 5:
//             {
//                 struct person newPerson;
//                 printf("Enter new person's id, name, age, height, and weight: ");
//                 newPerson.name = (char *)malloc(100 * sizeof(char)); // Adjust size as needed
//                 scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
//                 insertPerson(newPerson);
//                 break;
//             }
//             case 6:
//                 deleteMin();
//                 break;
//             case 7:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid option\n");
//         }
//     } while (option != 7);

//     if (heap != NULL)
//     {
//         for (int i = 0; i < heapSize; i++)
//         {
//             free(heap[i].name);
//         }
//         free(heap);
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person *heap;
int heapSize = 0;

//... (swap, heapifyDown, heapifyUp, insertPerson, deleteMin, displayHeap functions)
void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heapSize && heap[leftChild].age < heap[smallest].age)
        smallest = leftChild;

    if (rightChild < heapSize && heap[rightChild].age < heap[smallest].age)
        smallest = rightChild;

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index].age < heap[parent].age)
    {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insertPerson(struct person p)
{
    heapSize++;
    heap = (struct person *)realloc(heap, heapSize * sizeof(struct person));
    heap[heapSize - 1] = p;
    heapifyUp(heapSize - 1);
}

void deleteMin()
{
    if (heapSize == 0)
    {
        printf("Heap is empty.\n");
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);

    printf("Oldest person deleted from Min-Heap.\n");
}

void displayHeap()
{
    printf("Id\tName\t\tAge\tHeight\tWeight(pound)\n");
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\n", heap[i].id, heap[i].name, heap[i].age, heap[i].height, heap[i].weight);
    }
}

int readDataFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
    }

    int n;
    fscanf(file, "%d", &n);

    heap = (struct person *)malloc(n * sizeof(struct person));
    if (heap == NULL)
    {
        printf("Memory allocation error.\n");
        fclose(file);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        heap[i].name = (char *)malloc(100 * sizeof(char)); // Adjust size as needed
        if (heap[i].name == NULL)
        {
            printf("Memory allocation error.\n");
            fclose(file);
            for (int j = 0; j < i; j++)
            {
                free(heap[j].name);
            }
            free(heap);
            return 0;
        }

        fscanf(file, "%d %s %d %d %d", &heap[i].id, heap[i].name, &heap[i].age, &heap[i].height, &heap[i].weight);
        heapSize++;
    }

    fclose(file);

    // Print the data
    printf("Data read from the file:\n");
    displayHeap();

    return 1;
}
int main()
{
    int option;
    do
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age also display it\n");
        printf("3. Create a Max-heap based on the weight also display it\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                char filename[100];
                printf("Enter the filename: ");
                scanf("%s", filename);
                if (readDataFromFile(filename))
                {
                    printf("Data read from the file and stored in the array.\n");
                }
                break;
            }
            case 2:
                // Create a Min-heap based on the age and display it
                for (int i = heapSize / 2 - 1; i >= 0; i--)
                {
                    heapifyDown(i);
                }
                printf("Min-Heap based on Age:\n");
                displayHeap();
                break;
            case 3:
                // Create a Max-heap based on the weight and display it
                for (int i = heapSize / 2 - 1; i >= 0; i--)
                {
                    heapifyDown(i);
                }
                printf("Max-Heap based on Weight:\n");
                displayHeap();
                break;
            case 4:
            {
                if (heapSize > 0)
                {
                    int youngestIndex = 0;
                    for (int i = 1; i < heapSize; i++)
                    {
                        if (heap[i].age < heap[youngestIndex].age)
                        {
                            youngestIndex = i;
                        }
                    }
                    printf("Weight of the youngest person (age %d): %d pounds\n", heap[youngestIndex].age, heap[youngestIndex].weight);
                }
                else
                {
                    printf("No data available.\n");
                }
                break;
            }
            case 5:
            {
                struct person newPerson;
                printf("Enter new person's id, name, age, height, and weight: ");
                newPerson.name = (char *)malloc(100 * sizeof(char)); // Adjust size as needed
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                insertPerson(newPerson);
                break;
            }
            case 6:
                deleteMin();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 7);

    if (heap != NULL)
    {
        for (int i = 0; i < heapSize; i++)
        {
            free(heap[i].name);
        }
        free(heap);
    }

    return 0;
}
