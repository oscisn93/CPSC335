// Oscar Cisneros and Kevin Ortiz
// Project 4
// Problem 1: The Fibonacci Problem and the Golden Ratio
// Algorithm 1B: Fibonacci Problem - Golden Ratio
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
#include <iostream>
#include <cmath>

using namespace std;

// function prototype
// Find the fibonacci number using the golden ratio, using Fp
// which represents the preciding terms of Fn. The ratio approximates
// 1.61803. The function will return the nth term of the sequence.
// The user will enter 'p' and 'n' to calculate Fn, where p is a positive
// inter and non-floating point number.
// @param int p - the precedings term of Fn
// @param int n - the nth term of the sequence
// @return double - the value of the nth term of the sequence
double fib_goldenratio_equation4(int p, int n);

// main driver
int main()
{
    int p = 0;
    int n = 0;
    cout << "Enter the preceding term of Fn: ";
    cin >> p;
    cout << "Enter the nth term of the sequence: ";
    cin >> n;
    // print the first 20 terms of the sequence using fib_goldenratio_equation4
    for (int i = 0; i < 20; i++)
    {
        cout << fib_goldenratio_equation4(p, i) << " ";
    }
    return 0;
}
// function definition
double fib_goldenratio_equation4(int p, int n)
{
    // variable declaration
    double fp = 0;
    double fn = 0;
    // find Fp via formula Fn = [( 1 + sqrt(5) )^n - ( 1 - sqrt(5) )^n ] / ( 2^n * sqrt(5) )
    fp = ( pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
    // find Fn via formula Fn = Fp * (1.61803)^(n-p)
    fn = fp * pow(1.61803, (n - p));
    return fn;
}
