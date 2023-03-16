# Substring patterns search

## Problem Description
The problem we are solving to find running substrings of repeating characters in a string and replace them with the number of those characters followed by the characters themselves if there is any. I used a for loop with a while loop that iterates and keeps track of the current letters count as long as it repeats and then adds the letter or the pair to a stringstream that gets converted to a string at the end.

## Compilation and Executing
To run this program you must first compile it. You can either use gcc or clang, however if you would like to speed up the process simply run the bash script attached with `sh build.sh`. If you prefer gcc, you will have to compile it like this `g++ main.cpp -o main` and with clang `clang++ main.cpp -o main`. Once the program compiles you will then have to pipe the input file to the executable so that it can read it from standard input: `./main < test.in`. Again: the `.sh` file takes care of all of this for you if and will jsut print out the output of running the program with the given input file. 