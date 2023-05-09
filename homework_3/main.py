from typing import List
"""
Set Union:
    input: L: List[T], R: List[T]
    output: S: List[T], where S: L Union T
"""
def set_union(L, R):
    S = []
    # reduction step: sort both lists
    left = sorted(L)
    right = sorted(R)
    # insert minimum of both at each iteration
    while len(left) > 0 or len(right) > 0:
        # if either is empty append the rest of 
        # the other to and return S
        if len(left) == 0:
            S.extend(right)
            break
        elif len(right) == 0:
            S.extend(left)
            break
        a = left[0]
        b = right[0]
        if a < b:
            S.append(left.pop(0))
        elif b < a:
            S.append(right.pop(0))
        else:
            # if both are equal, append one and pop from both
            # until all copies of that number are removed
            num = left.pop(0)
            while (len(left) > 0 and left[0] == num):
                left.pop(0)
            while (len(right) > 0 and right[0] == num):
                right.pop(0)
            S.append(num)
    return S

"""
Set Difference:
    input: L: List[T], R: List[T]
    output: S: List[T], where S: L - R
"""
def set_difference(L, R):
    S = []
    left = sorted(L)
    S.extend(left)
    right = sorted(R)
    for element in right:
        if element in S:
            S.remove(element)
    return S
"""
Offline Ski Rental
    input: float, float, int
    output: boolean, indicating wether renting is cheaper than purchasing
"""
def offline_ski_rental(rental_price, purchase_price, number_days):
    return purchase_price >= rental_price * number_days
"""
List Reversal
    input: L: List[T]
    output: L: List[T] in place reversed list 
"""
def list_reversal(L: List[any]):
    for i in range(len(L)//2):
        L[i], L[len(L)-i-1] = L[len(L)-i-1], L[i]
    return L
"""
Pythagorean Triple Problem
    input: int, int
    output: (int, int, int) | None
    returns a pythagorean triple if one exists
    Pythagorean triple are three integers x, y, z,
    such that x^2 + y^2 = z^2 exists within 
    the bounds of [a, b].
"""
def pythagorean_triple_problem(a, b):
    for x in range(a, b+1):
        for y in range(x, b+1):
            for z in range(y, b+1):
                if x**2 + y**2 == z**2:
                    return (x, y, z)
    return None
"""
Find missing number in a List of N - 1 elements 
from 1 to N, with one number missing.
"""
def find_missing(A):
    for i in range(1, len(A) + 1):
        if i not in A:
            return i
    return None
"""
Sort a list using selection sort (O(N^2))
but only if it's not already sorted.
"""
def sort_list(L):
    if len(L) <= 2:
        return L
    if (L[0] < L[1]):
        for i in range(len(L) - 1):
            if L[i] > L[i+1]:
                return sorted(L)
        return L
    elif (L[0] > L[1]):
        for i in range(len(L) - 1):
            if L[i] < L[i+1]:
                return sorted(L, reverse=True)
        return L

