#include "C:\Users\AST\Desktop\repositories\AStar-Threaded-Search\projectFiles\include\dataStructures.h"

#include <stdlib.h>
#include <stdio.h>

// Tested: Passed
Vector* createVector(int initialCapacity) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->array = (int*)malloc(initialCapacity * sizeof(int));
    vec->size = 0;
    vec->capacity = initialCapacity;
    return vec;
}

// Tested: Passed
void destroyVector(Vector* vec) {
    free(vec->array);
    free(vec);
}

// Tested: Passed
void pushBack(Vector* vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->array = (int*)realloc(vec->array, vec->capacity * sizeof(int));
    }
    vec->array[vec->size++] = value;
}

// Tested: Passed
int popBack(Vector* vec) {
    if (vec->size == 0) {
        return -1; // or handle error
    }
    return vec->array[--vec->size];
}

// Tested: Passed
int getValue(const Vector* vec, int index) {
    if (index < 0 || index >= vec->size) {
        return -1; // or handle error
    }
    return vec->array[index];
}

// Tested: Passed
PriorityQueue* createPriorityQueue(int initialCapacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->priorities = (double*)malloc(initialCapacity * sizeof(double));
    pq->xs = (int*)malloc(initialCapacity * sizeof(int));
    pq->ys = (int*)malloc(initialCapacity * sizeof(int));
    pq->size = 0;
    pq->capacity = initialCapacity;
    return pq;
}

// Tested: Passed
void destroyPriorityQueue(PriorityQueue* pq) {
    free(pq->priorities);
    free(pq->xs);
    free(pq->ys);
    free(pq);
}

// Tested: Passed
void push(PriorityQueue* pq, double priority, int x, int y) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->priorities = (double*)realloc(pq->priorities, pq->capacity * sizeof(double));
        pq->xs = (int*)realloc(pq->xs, pq->capacity * sizeof(int));
        pq->ys = (int*)realloc(pq->ys, pq->capacity * sizeof(int));
    }
    int i = pq->size++;
    // Lower values are higher priority
    while (i > 0 && pq->priorities[(i - 1) / 2] > priority) {
        pq->priorities[i] = pq->priorities[(i - 1) / 2];
        pq->xs[i] = pq->xs[(i - 1) / 2];
        pq->ys[i] = pq->ys[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->priorities[i] = priority;
    pq->xs[i] = x;
    pq->ys[i] = y;
}

// Tested: Passed
void pop(PriorityQueue* pq, int* x, int* y) {
    if (pq->size == 0) {
        *x = -1; // or handle error
        *y = -1;
        return;
    }
    *x = pq->xs[0];
    *y = pq->ys[0];
    pq->size--;
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int minChild = (rightChild < pq->size && pq->priorities[rightChild] < pq->priorities[leftChild]) ? rightChild : leftChild;
        if (pq->priorities[minChild] >= pq->priorities[pq->size]) {
            break;
        }
        pq->priorities[i] = pq->priorities[minChild];
        pq->xs[i] = pq->xs[minChild];
        pq->ys[i] = pq->ys[minChild];
        i = minChild;
    }
    pq->priorities[i] = pq->priorities[pq->size];
}

// Tested: Passed
int isEmpty(const PriorityQueue* pq) {
    return pq->size == 0;
}