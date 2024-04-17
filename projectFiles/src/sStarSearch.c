#include "C:\Users\AST\Desktop\repositories\AStar-Threaded-Search\projectFiles\include\aStarSearch.h"
#include <stdlib.h>
#include <math.h>


// Tested: Passed
void initializeCells(Cell** cells, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cells[i][j].parentI = -1;
            cells[i][j].parentJ = -1;
            cells[i][j].f = INFINITY;
            cells[i][j].g = INFINITY;
            cells[i][j].h = INFINITY;
        }
    }
}

// Tested: Passed
void destroyCells(Cell** cells, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(cells[i]);
    }
    free(cells);
}

// Tested: Passed
double calculateHeuristicValue(int currentX, int currentY, int destX, int destY) {
    // Euclidean distance heuristic
    return sqrt((double)((destX - currentX) * (destX - currentX) + (destY - currentY) * (destY - currentY)));
}

void aStarSearchAlgorithm(int grid[][MAX_COLS], int numRows, int numCols, int startRow, int startCol, int goalRow, int goalCol) {
    // Implement A* search algorithm here
}

// Tested: Passed
int isValid(int x, int y, int numRows, int numCols) {
    return (x >= 0 && x < numRows && y >= 0 && y < numCols);
}

// Tested: Passed
int isGoal(int x, int y, int goalRow, int goalCol) {
    return (x == goalRow && y == goalCol);
}


double calculateCost(int currentX, int currentY, int nextX, int nextY) {
    // Assuming cost is always 1 for adjacent cells
    return 1.0;
}

void getNeighbours(int x, int y, int numRows, int numCols, Vector* neighbours) {
    // Implement function to get neighboring cells
}

int isObstacle(int x, int y, int grid[][MAX_COLS], int numRows, int numCols) {
    return (grid[x][y] == 0); // Assuming 0 represents an obstacle
}

void initializeGrid(int grid[][MAX_COLS], int numRows, int numCols) {
    // Implement function to initialize the grid
}

void printPath(Cell** cells, int startRow, int startCol, int goalRow, int goalCol) {
    // Implement function to print the path
}

void clearPath(Cell** cells, int numRows, int numCols) {
    // Implement function to clear the path
}
