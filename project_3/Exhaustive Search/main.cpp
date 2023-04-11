#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
// function prototype
// returns the number of paths that reach the end of the grid
// @param: grid - 2D vector of char
// return: int - number of paths that reach the end of the grid
int soccer_exhaustive(vector<vector<char>> grid);
// main driver
int main()
{
    // variable declaration
    // grid: type 2D vector of char - soccer field
    vector<vector<char>> grid{{{'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
                               {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
                               {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
                               {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
                               {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
                               {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
                               {'.', '.', '.', '.', '.', '.', '.', '.', '.'}}};
    // result: type int - number of paths that reach the end of the grid
    int result = soccer_exhaustive(grid);
    cout << "The number of different paths to cross the field: " << result << std::endl;
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
    int r = 8;
    // c: type int - number of columns in grid
    int c = 9;
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
