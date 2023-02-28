# Algorithm 1: Greedy Approach to Hamilton Problem

There are a set of cities laid out in a circle and each has a gas station and a known distance between them. Assuming that you are in a car that can drive a certain number of miles per gallon, find the preferred starting city such you can complete the roundtrip without getting stuck in between cities (as for some reason the gas stations all have only a limited number of gallons of gallons of fuel).
The input consists of a set of distances between the cities, a set of fuel amounts available at each city, and the miles per gallon the car uses.
The distance corresponds to how far the current city is from the following one. Assume the gas is always adequate to complete a roundtrip and that there is always a preferred city such that the trip can be succesfully completed.


# Instructions

You can run this algorithm one of two ways:

If you are simply running it agains the sample test input you can run the test.sh file which will run the following command:
`python3 main.py < 1.in` and output the result to the terminal. However, if you have additional testcases you'd like to run against the program you can simply include them in additional `.in` files in the same format as the present file where the first line is a space separated list of city distances, the second line is a space separated list of fuel per city, and the third line contains an integer representing the number of miles per gallon. Additionally if youd like to automate the comparison you can write the expected output into a `.out` file and run the run `python3 main.py < yourfile.in > output` followed by `diff yourfile.out output`. This will show you if there is any difference between the expected output and the output from my program. If there is none it will simply not print anything.