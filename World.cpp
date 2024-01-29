#include <iostream>
#include <vector>

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
    // Define the grid with costs of traversal
    std::vector<std::vector<int>> costs = {
        {2, 3, 1, 4, 2},
        {3, 2, 1, 2, 3},
        {4, 2, 3, 3, 1},
        {2, 1, 2, 3, 2},
        {3, 2, 3, 2, 2}
    };

    // Print the grid with costs of traversal
    std::cout << "Costs of traversal:\n";
    printCosts(costs);

    return 0;
}
