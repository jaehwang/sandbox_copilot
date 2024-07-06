#include <stdio.h>
#include <stdlib.h> // Add this line to include the <stdlib.h> header file
#include <string.h> // Add this line to include the <string.h> header file
#include "util.h"

/**
 * @brief Parses command line arguments and extracts the number.
 *
 * This function takes the command line arguments, argc and argv, and extracts
 * the number from them. The extracted number is stored in the variable pointed
 * to by the number parameter.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @param number A pointer to an integer where the extracted number will be stored.
 * @return Returns 0 if the number was successfully extracted, 1 otherwise.
 */
int parse_args(int argc, char *argv[], int *number) {
    if (argc < 2) {
        printf("Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                *number = atoi(argv[i + 1]); // Use dereference operator (*) to assign the value to the pointer
                break;
            } else {
                printf("Error: -n option requires a number argument.\n");
                return 1;
            }
        }
    }

    return 0;
}

/**
 * @brief Checks if a number is prime.
 *
 * This function takes a number as input and checks if it is a prime number.
 * Returns 1 if the number is prime, 0 otherwise.
 *
 * @param num The number to check.
 * @return 1 if the number is prime, 0 otherwise.
 */
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}
/**
 * @brief Counts the number of prime numbers in the given range.
 *
 * This function takes a start and end number and counts the number of prime
 * numbers within that range (inclusive). The count is returned.
 *
 * @param start The start number of the range.
 * @param end The end number of the range.
 * @return The number of prime numbers in the range.
 */
int count_primes(int start, int end) {
    int count = 0;

    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            count++;
        }
    }

    return count;
}