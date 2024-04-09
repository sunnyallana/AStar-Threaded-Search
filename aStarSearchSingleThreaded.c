/* 
   A* Search Algorithm (Single-Threaded Version)
   ----------------------------------------------------------
   This version of the A* search algorithm will run in a single
   thread without utilizing concurrency.

   Steps:
   1. Initialize the start node and the open list with the start node.
   2. Loop until either the goal node is found or the open list is empty:
      a. Select the node with the lowest f-score from the open list.
      b. If this node is the goal node, reconstruct the path to the goal.
      c. Otherwise, expand the selected node by examining its neighbors:
         i. Calculate the tentative g-score for each neighbor.
         ii. If a neighbor has not been evaluated or has a lower g-score,
             update its scores and set its parent to the current node.
         iii. Add the neighbor to the open list if it's not already there.
   3. If the open list is empty and the goal node has not been reached,
      the search fails (no path to the goal).
*/

/*
Making use of this resource to understand the A* algorithm:
Reference YouTube Video: https://youtu.be/W9zSr9jnoqY?feature=shared
*/

#include <stdio.h>

// g(n): Actual cost to the path from the start node to n.
// h(n): Heuristic estimate of the cost from n to the goal node calculated using the Manhattan distance i.e abs(x1 - x2) + abs(y1 - y2).
// f(n): f(n) = g(n) + h(n) (total estimated cost of the cheapest solution through n).






















