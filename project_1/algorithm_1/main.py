def parse_input():
    city_distances = [int(i) for i in input().split(' ')]
    fuel = [int(j) for j in input().split(' ')]
    mpg = int(input())
    return (city_distances, fuel, mpg)


cd, f, m = parse_input()


def find_preferred_index(cd, f, m):
    n = len(cd)
    idx = f.index(max(f))
    visited = 0
    while visited < n:
        if f[idx] * m - cd[idx] > 0:
            return idx
        visited += 1
        idx = (idx + 1) % n


print(find_preferred_index(cd, f, m))
