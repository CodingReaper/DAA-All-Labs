#include <stdio.h>
#include<stdbool.h>
// Function to calculate GCD using Euclid's algorithm
int euclids_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate GCD using consecutive integer checking algorithm
int consecutive_integer_gcd(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate GCD using common prime factors
int common_prime_factors_gcd(int a, int b) {
    int gcd = 1;
    for (int i = 2; i <= min(a, b); i++) {
        while (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

// Function to generate prime numbers using the sieve of Eratosthenes algorithm
void sieve_of_eratosthenes(int limit, bool primes[]) {
    // Initialize all elements of the array to true
    for (int i = 0; i <= limit; i++) {
        primes[i] = true;
    }

    for (int p = 2; p * p <= limit; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= limit; i += p) {
                primes[i] = false;
            }
        }
    }
}

int main() {
    int a = 31415;
    int b = 14142;

    // Test and compare the performance of the GCD algorithms
    printf("Euclid's GCD: %d\n", euclids_gcd(a, b));
    printf("Consecutive integer checking GCD: %d\n", consecutive_integer_gcd(a, b));
    printf("Common prime factors GCD: %d\n", common_prime_factors_gcd(a, b));

    // Generate a list of primes using the sieve of Eratosthenes algorithm
    int limit = 1000;
    bool primes[limit + 1];
    sieve_of_eratosthenes(limit, primes);

    printf("List of prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
