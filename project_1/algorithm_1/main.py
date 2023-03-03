def parse_input():
    # creates the necessary variables by reading from a file you pipe in
    city_distances = [int(i) for i in input().split(' ')]
    fuel = [int(j) for j in input().split(' ')]
    mpg = int(input())
    return (city_distances, fuel, mpg)


cd, f, m = parse_input()


def find_preferred_index(cd, f, m):
    # we need the index in case we have to check every station
    n = len(cd)
    # start at the highest fuel value (greedy)
    idx = f.index(max(f))
    # to keep track of where we are in case the 
    # highest fuel isn't the preferred city
    visited = 0
    while visited < n:
        # if there is enough fuel at the current
        # gas station we set it as the preferred city
        if f[idx] * m >= cd[idx]:
            return idx
        # otherwise mark the current city as visited
        visited += 1
        # we set the index to idx + 1 but we mod by 
        # size so we never go out of bounds
        idx = (idx + 1) % n


print(find_preferred_index(cd, f, m))
