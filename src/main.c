#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "queue.h"

/**
 * 큐를 생성하고, 요소를 추가하고, 요소를 제거하는 예제 코드입니다.
 * 
 * @file main.c
 * @brief 큐 예제 코드
 * @date 작성일
 * 
 * @details 이 코드는 큐를 생성하고, 요소를 추가하고, 요소를 제거하는 과정을 보여줍니다.
 *          큐가 제대로 생성되지 않은 경우 오류 메시지를 출력하고, 프로그램을 종료합니다.
 *          큐에는 0, 1, 2 세 개의 정수를 추가하고, 큐에서 요소를 제거하여 출력합니다.
 *          큐를 사용한 후에는 큐를 파괴합니다.
 */
static int queue_demo() {

    Queue *q = queue_create();
    if (q == NULL) {
        fprintf(stderr, "Failed to create queue.\n");
        return EXIT_FAILURE;
    }

    int nums[] = {0,1,2};

    int size = sizeof(nums)/sizeof(int);

    for (int i=0; i < size; i++) { 
        enqueue(q, nums+i);
    }

    int *x;
    while ((x = dequeue(q)) != NULL) {
        printf("%d\n", count_primes(1, *x));
    }
    queue_destroy(q);
    q = NULL;

    return 0;
}

int main(int argc, const char *argv[]) {
    int res = 0, n = 0, err = 0;

    err = parse_args(argc, argv, &n);

    if (err != 0) {
        fprintf(stderr, "Error parsing arguments\n");
        return EXIT_FAILURE;
    } 

    if (n >= 1) {
        res = count_primes(1, n);
        printf("Number of primes between 1 and %d: %d\n", n, res);
    }

    err = queue_demo();

    if (err != 0) {
        fprintf(stderr, "Error: queue demo\n");
        return EXIT_FAILURE;
    } 

    return 0;
}
