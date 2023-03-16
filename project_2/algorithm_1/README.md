# Substring patterns search

## Problem Description
The problem we are solving is a substring search algorithm. The problem is complicated by the fact that there are multiple substrigns to search for and that they must be ordered. However, there is a data structure which conveniently can order our items in C++- the map. All that was left was to find the indexes of each city in the large array and input them into the map where they would be sorted automatically (it uses a red-black tree internally, so its always sorted). Finally we use two string builder to create the dersired output and pass it to standard output.

## Compilation and Executing
To run this program you must first compile it. You can either use gcc or clang, however if you would like to speed up the process simply run the bash script attached with `sh build.sh`. If you prefer gcc, you will have to compile it like this `g++ main.cpp -o main` and with clang `clang++ main.cpp -o main`. Once the program compiles you will then have to pipe the input file to the executable so that it can read it from standard input: `./main < in2A.txt`. Again: the `.sh` file takes care of all of this for you if and will jsut print out the output of running the program with the given input file. 