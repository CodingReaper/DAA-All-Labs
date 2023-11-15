#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int lower, int upper) {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between lower and upper
    int num = (rand() % (upper - lower + 1)) + lower;

    return num;
}

int main() {
    int lower, upper;

    printf("Enter the lower bound: ");
    scanf("%d", &lower);

    printf("Enter the upper bound: ");
    scanf("%d", &upper);

    int randomNum = generateRandomNumber(lower, upper);
    printf("Random number between %d and %d: %d\n", lower, upper, randomNum);

    return 0;
}
