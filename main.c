
#include <stdio.h>
#include <stdlib.h> // Add this line to include the <stdlib.h> header file
#include <string.h> // Add this line to include the <string.h> header file
#include "util.h"

int main(int argc, const char *argv[]) {
    int res = 0, n = 0, err = 0;

    err = parse_args(argc, argv, &n);

    if (err) {
        return -1;
    } else {
        printf("Hello, World! %d\n",n);
    }

    if (n >= 1) {
        res = count_primes(1, n);
        printf("Number of primes between 1 and %d: %d\n", n, res);
    }

    return 0;
}
