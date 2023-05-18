def parse():
    data = []
    for lines in input().lines():
        data.append([int(i) for i in lines.split(' ')])
    return data

def largest_sum_subarray(array):
    b = 0
    e = 1
    max_sum  = array[0]
    for i in range(len(array)):
        cur_sum = array[i]:
        if cur_sum > max_sum:
            max_sum = cur_sum
            b = i
            e = i + 1
        for j in range(i+1, len(array)):
            cur_sum += array[j]
            if cur_sum > max_sum:
                max_sum = cur_sum
                b = i
                e = j + 1
    return b, e

def main():
    lists = parse()
    for l in lists:
        print(l)
        b, e = largest_sum_subarray(l)
        print(f"b: {b}, e: {e}")

main()

# T(n) = n(n+1)/2 = O(n^2)
