from sys import stdin


def parse():
    inputs = []
    for i in stdin:
        if i[0] == 'a':
            opening = i.index('[')
            closing = i.index(']')
            s = [t.strip(',').strip('“').strip('”').strip('‘').strip('’')
                 for t in i[opening + 2: closing - 1].split(' ')]
            inputs.append(s)
    return inputs


inputs = parse()


def solve(target, strings):
    print(target)
    
    largest = max(strings)
    print(largest)
    return list(enumerate(strings))


for i in range(3):
    print(solve(inputs.pop(0)[0], inputs.pop(0)))
