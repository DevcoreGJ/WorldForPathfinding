#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int rows = 5;
const int cols = 5;

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

    return 0;
}
