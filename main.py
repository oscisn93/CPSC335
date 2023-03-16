import os

ALGORITHMS = 3

for i in range(1, ALGORITHMS + 1):
    dirname = f'algorithm_{i}'
    os.mkdir(dirname)

