#ifndef ASTAR_H
#define ASTAR_H

#include "DataStructures.h"

#define MAX_COLS 100 // Define the maximum number of columns in the grid

// Definition of a cell in the grid
typedef struct {
    int parentI;    // Row index of the parent cell
    int parentJ;    // Column index of the parent cell
    double f;       // Total cost of reaching this cell from the start cell
    double g;       // Cost of reaching this cell from the start cell
    double h;       // Heuristic cost from this cell to the goal cell
} Cell;

// Function declarations for A-star search algorithm
void initializeCells(Cell** cells, int numRows, int numCols);
void destroyCells(Cell** cells, int numRows);
double calculateHeuristicValue(int currentX, int currentY, int destX, int destY);
void aStarSearchAlgorithm(int grid[][MAX_COLS], int numRows, int numCols, int startRow, int startCol, int goalRow, int goalCol);

// Utility functions
int isValid(int x, int y, int numRows, int numCols);
int isGoal(int x, int y, int goalRow, int goalCol);
double calculateCost(int currentX, int currentY, int nextX, int nextY);
void getNeighbours(int x, int y, int numRows, int numCols, Vector* neighbours);
int isObstacle(int x, int y, int grid[][MAX_COLS], int numRows, int numCols);
void initializeGrid(int grid[][MAX_COLS], int numRows, int numCols);
void printPath(Cell** cells, int startRow, int startCol, int goalRow, int goalCol);
void clearPath(Cell** cells, int numRows, int numCols);

#endif
