#!/bin/bash

echo "-----------------------------------------------------------------"
echo "Algorithmic Efficieny Comparisons"
echo "-----------------------------------------------------------------"
echo "Using Dynamic Programming:"
echo "-----------------------------------------------------------------"

for i in 1 2 3 4
do
    ./dynamic_programming/main < "./inputs/$i.in"
    echo "-----------------------------------------------------------------"
done

echo "Using Exhaustive Search:"
echo "-----------------------------------------------------------------"

for i in 1 2 3 4
do
    ./exhaustive_search/main < "./inputs/$i.in"
    echo "----------------------------------------------------------------"
done
