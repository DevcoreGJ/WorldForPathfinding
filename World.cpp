#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

const int rows = 5;
const int cols = 5;
const int INFINITY_VALUE = 1e9;  // A sufficiently large constant

// Structure to represent a node in the grid
struct Node {
    int row, col, distance;

    // Define the less-than operator for sorting in the priority queue
    bool operator<(const Node& other) const {
        return distance > other.distance;  // Note: Using '>' for min-heap
    }
};

// Function to print the grid with costs of traversal
void printCosts(const std::vector<std::vector<int>>& costs) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << costs[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    // Seed for random number generation
    std::srand(std::time(0));

    // Define the grid with costs of traversal
    std::vector<std::vector<int>> costs = {
        {2, 3, 1, 4, 2},
        {3, 2, 1, 2, 3},
        {4, 2, 3, 3, 1},
        {2, 1, 2, 3, 2},
        {3, 2, 3, 2, 2}
    };

    // Randomly select start and end nodes
    int startRow = std::rand() % rows;
    int startCol = std::rand() % cols;
    int endRow, endCol;

    do {
        endRow = std::rand() % rows;
        endCol = std::rand() % cols;
    } while (startRow == endRow && startCol == endCol);

    // Print the grid with costs of traversal
    std::cout << "Costs of traversal:\n";
    printCosts(costs);

    // Print the randomly selected start and end nodes
    std::cout << "Start Node: (" << startRow << "," << startCol << ")\n";
    std::cout << "End Node:   (" << endRow << "," << endCol << ")\n";

    // Initialize distances array
    std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, INFINITY_VALUE));

    // Priority queue to store nodes based on distance
    std::priority_queue<Node, std::vector<Node>, std::less<Node>> pq;

    // Add start node to the priority queue
    pq.push({ startRow, startCol, 0 });
    distance[startRow][startCol] = 0;

    // Dijkstra's algorithm
    while (!pq.empty()) {
        // Pop the node with the minimum distance
        Node current = pq.top();
        pq.pop();

        // Explore neighbors and update distances
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;

                int newRow = current.row + i;
                int newCol = current.col + j;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int cost = costs[newRow][newCol];
                    int newDistance = current.distance + cost;

                    if (newDistance < distance[newRow][newCol]) {
                        distance[newRow][newCol] = newDistance;
                        pq.push({ newRow, newCol, newDistance });
                    }
                }
            }
        }
    }

    // Print the distances from the start node to all other nodes
    std::cout << "\nDistances from the Start Node:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
