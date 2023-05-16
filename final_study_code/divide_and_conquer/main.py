def summation(vector):
    n = len(vector)
    if n == 0:
        return n
    elif n == 1:
        return vector[0]
    else:
        midpoint = int(n/2)
        left, right = summation(vector[:midpoint]), summation(vector[midpoint:])
        return left + right


def summation2(vec):
    sum = 0
    for n in vec:
        sum += n

    return sum

