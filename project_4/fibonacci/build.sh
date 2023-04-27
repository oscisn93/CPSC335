#!/bin/bash

#Clear any previously compiled files
rm *.o

#echo "compile fib_exhaustive.cpp using g++ compiler standard 2017"
#g++ -std=c++17 fib_exhaustive.cpp -o fib_exhaustive

echo "compile fib_goldenratio.cpp using g++ compiler standard 2017"
g++ -std=c++17 fib_goldenratio.cpp -o fib_goldenratio

#echo "Run the fib_exhaustive.cpp Program:"
#./fib_exhaustive

echo "Run the fib_goldenratio.cpp Program:"
./fib_goldenratio

# For cleaner working directory, remove all .o files
rm *.o

echo "Script file terminated."
