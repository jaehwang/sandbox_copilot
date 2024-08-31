#include <stdio.h>
#include <stdlib.h> // Add this line to include the <stdlib.h> header file
#include <string.h> // Add this line to include the <string.h> header file
#include "util.h"

/**
 * @brief 명령 줄 인수를 구문 분석하고 숫자를 추출합니다.
 *
 * 이 함수는 명령 줄 인수인 argc와 argv를 가져와서 숫자를 추출합니다. 추출된 숫자는 number 매개변수가 가리키는 변수에 저장됩니다.
 *
 * @param argc 명령 줄 인수의 개수입니다.
 * @param argv 명령 줄 인수를 포함하는 문자열 배열입니다.
 * @param number 추출된 숫자가 저장될 정수를 가리키는 포인터입니다.
 * @return 숫자가 성공적으로 추출되면 0을 반환하고, 그렇지 않으면 1을 반환합니다.
 */
int parse_args(int argc, const char *argv[], int *number) {
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

