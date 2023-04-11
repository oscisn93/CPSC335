// Oscar Cisneros and Kevin Ortiz
// Algorithm 2: Soccer Opponent Avoidance - Dynamic Programming
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <string>
#include <vector>

auto parse() {
    std::vector<std::vector<char>> grid;
    for (std::string line; std::getline(std::cin, line);) {
        std::vector<char> row;
        for (char c: line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    return grid;
}

int soccer_opponent_aviodance(std::vector<std::vector<char>> grid) {
    if (grid[0][0] == 'X')
        return 0;
    int matrix [grid.size()][grid[0].size()];

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            matrix[i][j] = 0;
        }
    }

    matrix[0][0] = 1;


    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int above = 0, left = 0;
            if (grid[i][j] == 'X') {
                matrix[i][j] = 0;
                continue;
            }
            if (i > 0 && grid[i-1][j] == '.')
                above = matrix[i-1][j];
            if (j > 0 && grid[i][j - 1] == '.')
                left = matrix[i][j - 1];
            matrix[i][j] += (above + left);
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return matrix[grid.size() -1][grid[0].size() - 1];
}

int main(int argc, char const *argv[]) {
    auto grid = parse();
    soccer_opponent_aviodance(grid);
    // std::cout << "Total paths: " << soccer_opponent_aviodance(grid) << std::endl;
    
    return 0;
}
