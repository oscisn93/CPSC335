// Oscar Cisneros and Kevin Ortiz
// Algorithm 2: Soccer Opponent Avoidance - Dynamic Programming
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
// parse the input from stdin
// from input, create 2d char vector
// that represents the soccer field
auto parse()
{
  // the grid will be a 2d char vector
  std::vector<std::vector<char>> grid;
  // process each stdin line independently
  for (std::string line; std::getline(std::cin, line);)
  {
    // create a new vector for each line
    // populate it with the characters
    std::vector<char> row;
    for (char c : line)
    {
      row.push_back(c);
    }
    // push the row onto the grid and repeat
    grid.push_back(row);
  }
  return grid;
}
// dynamic programming approach to the problem
int soccer_opponent_aviodance(std::vector<std::vector<char>> grid)
{
  // check if the first square is blocked
  // if so no paths exist
  if (grid[0][0] == 'X')
    return 0;
  //  use a 2-D array to track the number of paths at each square
  int matrix[grid.size()][grid[0].size()];
  //  fill the matrix with 0s
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      matrix[i][j] = 0;
    }
  }
  //  first one is a path since it's not X
  matrix[0][0] = 1;
  // iterate through the grid and calculate paths per square
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      int above = 0, left = 0;
      // if the current square has an X
      // set the matrix value to 0
      // and continue iterating
      if (grid[i][j] == 'X')
      {
        matrix[i][j] = 0;
        continue;
      }
      // case: the grid quare contains a '.'
      // if a path exists above and the square
      // is not on the first row
      if (i > 0 && grid[i - 1][j] == '.')
        // set above value to greater than 0
        above = matrix[i - 1][j];
      // repeat for the left value
      if (j > 0 && grid[i][j - 1] == '.')
        left = matrix[i][j - 1];
      // add the number of paths above
      // and to the left of the matrix square
      matrix[i][j] += (above + left);
    }
  }
  // the total number of paths is the value at the
  // bottom right square of the grid
  return matrix[grid.size() - 1][grid[0].size() - 1];
}

int main(int argc, char const *argv[])
{
  // initialize the grid
  auto grid = parse();
  // start the timer
  auto start = std::chrono::high_resolution_clock::now();
  // calulate the number of paths
  int paths = soccer_opponent_aviodance(grid);
  // stop the clock
  auto stop = std::chrono::high_resolution_clock::now();
  // calculate duration as microseconds
  auto t = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  // print output to stdout
  std::cout << "Total paths: " << paths << "\n";
  std::cout << "Empirical time: " << t.count() << " us.\n";
  return 0;
}
