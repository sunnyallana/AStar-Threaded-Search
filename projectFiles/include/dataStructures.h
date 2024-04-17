#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Definition of Vector
typedef struct {
    int* array;     // Array to store elements
    int size;       // Current number of elements in the vector
    int capacity;   // Maximum capacity of the vector
} Vector;

// Function declarations for vector operations
Vector* createVector(int initialCapacity);
void destroyVector(Vector* vec);
void pushBack(Vector* vec, int value);
int popBack(Vector* vec);
int getValue(const Vector* vec, int index);

// Definition of PriorityQueue
typedef struct {
    double* priorities; // Array to store priorities
    int* xs;            // Array to store x coordinates
    int* ys;            // Array to store y coordinates
    int size;           // Current number of elements in the priority queue
    int capacity;       // Maximum capacity of the priority queue
} PriorityQueue;

// Function declarations for priority queue operations
PriorityQueue* createPriorityQueue(int initialCapacity);
void destroyPriorityQueue(PriorityQueue* pq);
void push(PriorityQueue* pq, double priority, int x, int y);
void pop(PriorityQueue* pq, int* x, int* y);
int isEmpty(const PriorityQueue* pq);

#endif