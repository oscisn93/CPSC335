// Oscar Cisneros and Kevin Ortiz
// Project 4
// Problem 1: The Fibonacci Problem and the Golden Ratio
// Algorithm 1A: Fibonacci Problem - Exhaustive Search
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>

using namespace std;

// function prototype
// Recursive exhaustive algorithm to calculate the 𝑛𝑡ℎ terms of the sequence.
// @param int n - the nth term of the sequence
// @return int - the nth term of the sequence
int fib_exhaustive(int n);

// main driver
int main()
{
    int n = 15;
    int fib = fib_exhaustive(n);
    cout << "The " << n << "th term of the Fibonacci sequence is: " << fib << endl;

    return 0;
}
// function definition
int fib_exhaustive(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib_exhaustive(n - 1) + fib_exhaustive(n - 2);
    }
}
