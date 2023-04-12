// Oscar Cisneros and Kevin Ortiz
// Algorithm 1: Soccer Opponent Avoidance - Exhaustive Search
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>

using namespace std;
// function prototype
// returns the number of paths that reach the end of the grid
// @param: grid - 2D vector of char
// return: int - number of paths that reach the end of the grid
int soccer_exhaustive(vector<vector<char>> grid);
std::vector<std::vector<char>> parse();

// main driver
int main()
{
    auto grid = parse();
    // start: type high_resolution_clock::time_point - start time
    auto start = std::chrono::high_resolution_clock::now();
    // result: type int - number of paths that reach the end of the grid
    int result = soccer_exhaustive(grid);
    // stop: type high_resolution_clock::time_point - stop time
    auto stop = std::chrono::high_resolution_clock::now();
    // empirical_timing: type duration<double> - empirical timing
    auto empirical_timing = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "The number of different paths to cross the field: " << result << endl;
    cout << "Empirical time: " << empirical_timing.count() << " microseconds" << endl;
    return 0;
}
// function definition
// returns the number of paths that reach the end of the grid
// @param: grid - 2D vector of char
// return: int - number of paths that reach the end of the grid
int soccer_exhaustive(vector<vector<char>> grid)
{
    // variable declaration
    // r: type int - number of rows in grid
    int r = grid.size();
    // c: type int - number of columns in grid
    int c = grid[0].size();
    // len: type int - length of the path
    int len = r + c - 2;
    // counter: type int - number of valid paths in grid
    int counter = 0;
    // for bits from 0 to 2^len - 1 inclusive
    for (int bits = 0; bits <= (pow(2, len) - 1); bits++)
    {
        // variable declaration
        // candidate: type vector<char> - empty list of moves
        vector<char> candidate;
        // row: type int - row index
        int row = 0;
        // col: type int - column index
        int col = 0;
        // for k from 0 to len - 1 inclusive
        for (int k = 0; k <= (len - 1); k++)
        {
            // variable declaration
            // bit: type int - bit at index k
            int bit = (bits >> k) & 1;
            // if bit is 1, move right
            if (bit == 1)
            {
                candidate.push_back('r');
                col++;
            }
            // if bit is 0, move down
            else
            {
                candidate.push_back('d');
                row++;
            }
            // if the candidate goes outside of the grid or the candidate hits an X break
            if (row >= r || col >= c || grid[row][col] == 'X')
                break;
            // if the candidate reaches the end of the grid (r-1, c-1), increment counter
            if ((row == r - 1) && (col == c - 1))
            {
                counter++;
                break;
            }
        }
    }
    return counter;
}
// variable declaration
// grid: type 2D vector of char - soccer field
std::vector<std::vector<char>> parse()
{
    std::vector<std::vector<char>> grid;
    for (std::string line; std::getline(std::cin, line);)
    {
        std::vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    return grid;
}