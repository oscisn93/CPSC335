// Oscar Cisneros and Kevin Ortiz
// Algorithm 2: Soccer Opponent Avoidance - Dynamic Programming
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

auto parse() {
  std::vector<std::vector<char>> grid;
  for (std::string line; std::getline(std::cin, line);) {
    std::vector<char> row;
    for (char c : line) {
      row.push_back(c);
    }
    grid.push_back(row);
  }
  return grid;
}

int soccer_opponent_aviodance(std::vector<std::vector<char>> grid) {
  // check if the first square is blocked
  // if so no paths exist 
  if (grid[0][0] == 'X')
    return 0;
   //  use a 2-D array to track the number of paths at each square
  int matrix[grid.size()][grid[0].size()];
  //  fill the matrix with 0s
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      matrix[i][j] = 0;
    }
  }
  //  first one is a path since it's not X
  matrix[0][0] = 1;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      int above = 0, left = 0;
      if (grid[i][j] == 'X') {
        matrix[i][j] = 0;
        continue;
      }
      if (i > 0 && grid[i - 1][j] == '.')
        above = matrix[i - 1][j];
      if (j > 0 && grid[i][j - 1] == '.')
        left = matrix[i][j - 1];
      matrix[i][j] += (above + left);
    }
  }
  return matrix[grid.size() - 1][grid[0].size() - 1];
}

int main(int argc, char const *argv[]) {
  auto grid = parse();
  auto start = std::chrono::high_resolution_clock::now();
  int paths = soccer_opponent_aviodance(grid);
  auto stop = std::chrono::high_resolution_clock::now();
  auto t = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Total paths: " << paths << "\n";
  std::cout << "Empirical time: " << t.count() << " us.\n";
  return 0;
}
