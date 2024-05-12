#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
#include <cmath>

using namespace std;

string startNode = "EE_BLOCK";
string goalNode = "SPORTS_ROOM";

class Node {
public:
    string id;
    vector<string> neighbors;
};

class Path {
public:
    vector<string> nodes;
    int cost;  // g(x) - the actual cost of reaching the current node
};

class ComparePaths {
public:
    bool operator()(const Path& p1, const Path& p2) const {
        return p1.cost > p2.cost;
    }
};

priority_queue<Path, vector<Path>, ComparePaths> pq;
Path minCostPath = {{}, INT_MAX}; // Initialize with high cost

vector<Node> graph = {
    {"EE_BLOCK", {"BASHIR_SHWARMA", "CS_BLOCK"}},
    {"BASHIR_SHWARMA", {"BADAR_DHABBA", "CS_BLOCK"}},
    {"CS_BLOCK", {"MULTIPURPOSE_BLOCK","BADAR_DHABBA"}},
    {"MULTIPURPOSE_BLOCK", {"SPORTS_ROOM"}},
    {"BADAR_DHABBA", {"MULTIPURPOSE_BLOCK","SPORTS_ROOM"}},
    {"SPORTS_ROOM", {}}
};


map<string, pair<int, int>> nodeCoordinates = {
    {"EE_BLOCK", {0, 0}},
    {"BASHIR_SHWARMA", {8, 4}},
    {"CS_BLOCK", {0, 6}},
    {"MULTIPURPOSE_BLOCK", {2, 10}},
    {"BADAR_DHABBA", {8, 12}},
    {"SPORTS_ROOM", {4, 15}}
};

map<string, int> actualCost = {
    {"EE_BLOCK", 0}, // Actual cost to reach start node is 0
    {"BASHIR_SHWARMA", 4},
    {"CS_BLOCK", 6},
    {"BADAR_DHABBA", 12},
    {"SPORTS_ROOM", 15} // Actual cost from start to SPORTS_ROOM
};

// Function to calculate Manhattan distance between two nodes
int manhattanDistance(const string& node1, const string& node2) {
    auto& coord1 = nodeCoordinates[node1];
    auto& coord2 = nodeCoordinates[node2];

    return abs(coord1.first - coord2.first) + abs(coord1.second - coord2.second);
}

// Function to calculate Euclidean distance between two nodes
double euclideanDistance(const string& node1, const string& node2) {
    auto& coord1 = nodeCoordinates[node1];
    auto& coord2 = nodeCoordinates[node2];

    int dx = coord1.first - coord2.first;
    int dy = coord1.second - coord2.second;

    return sqrt(dx * dx + dy * dy);
}

void aStarSearch() {
    map<string, int> nodeLookup; // Map for node lookup
    for (int i = 0; i < graph.size(); ++i) {
        nodeLookup[graph[i].id] = i; // Store index of each node
    }

    while (!pq.empty()) {
        Path currentPath = pq.top();
        pq.pop();

        string currentNode = currentPath.nodes.back();

        if (currentNode == goalNode) {
            if (currentPath.cost < minCostPath.cost) {
                minCostPath = currentPath;
            }
            return;
        }

        for (const string& neighbor : graph[nodeLookup[currentNode]].neighbors) {
            Path newPath = currentPath;
            newPath.nodes.push_back(neighbor);

            // Calculate actual cost g(x)
            int neighborCost = actualCost[neighbor];
            newPath.cost += neighborCost;

            int heuristic = manhattanDistance(neighbor, goalNode); // Manhattan distance
            // double heuristic = euclideanDistance(neighbor, goalNode); // Euclidean distance
            newPath.cost += heuristic;

            pq.push(newPath);
        }
    }
}

int main() {
    Path initialPath;
    initialPath.nodes.push_back(startNode);
    initialPath.cost = 0;
    pq.push(initialPath);

    aStarSearch();

    cout << "Minimum Cost Path: ";
    for (size_t i = 0; i < minCostPath.nodes.size(); ++i) {
        cout << minCostPath.nodes[i];
        if (i < minCostPath.nodes.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Cost: " << minCostPath.cost << endl;

    return 0;
}
