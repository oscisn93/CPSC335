#!/bin/bash

for i in 1
do
    echo "Algorithmic Efficieny Comparisons\n"
    echo "\n-----------------------------------------------------------------\n"
    echo "Using Dynamic Programming:\n"
    ./dynamic_programming/main < "./inputs/$i.in"
    echo "\n-----------------------------------------------------------------\n"
    echo "Using Exhaustive Search:\n"
    ./Exhaustive\ Search/main
    echo "\n-----------------------------------------------------------------\n"
done
