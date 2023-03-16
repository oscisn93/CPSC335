# Merge Sorted Array

## Problem Description
This problem involves reading in a group of arrays and then merging them, the problem is complicated by having to read and parse the arrays from the file. The way I got around this is by simply creating a flag that tells the program wether it is inside the arrays- it is set to true when the line starts with `A` and only reset when the line is empty or there is a newline. Everytime the flag is set to true we push a new array into the array of arrays. Once all arrays are parsed we then call Quicksort on each array and print it to standard output.

## Compilation and Executing
To run this program you must first compile it. You can either use gcc or clang, however if you would like to speed up the process simply run the bash script attached with `sh build.sh`. If you prefer gcc, you will have to compile it like this `g++ main.cpp -o main` and with clang `clang++ main.cpp -o main`. Once the program compiles you will then have to pipe the input file to the executable so that it can read it from standard input: `./main < in2A.txt`. Again: the `.sh` file takes care of all of this for you if and will jsut print out the output of running the program with the given input file. 
