def summation(vector):
  n = len(vector)
  if n == 0:
    return n
  elif n == 1:
    return vector[0]
  else:
    midpoint = int(n/2)
    left = summation(vector[:midpoint])
    right =  summation(vector[midpoint:])
    return left + right


def summation2(vec):
  sum = 0
  for n in vec:
    sum += n
  return sum


def merge(left, right):
   if len(left) == 1 and len(right) == 1:
     n, m = left[0], right[0]
     if n < m:
       return [n, m]
     else:
       return [m, n]
   else:
     output = []
     while len(left) > 0 and len(right) > 0:
       n, m = left[0], right[0]
       if n < m:
         output.append(left.pop(0))
       elif m < n:
         output.append(right.pop(0))
       else:
         output.extend([left.pop(0), right.pop(0)])
     if len(left) > 0:
       output.extend(left)
     elif len(right) >0:
       output.extend(right)
     return output

def merge_sort(vec):
   if len(vec) == 1:
     return vec
   else:
     midpoint = len(vec) // 2
     left = merge_sort(vec[:midpoint])
     right = merge_sort(vec[midpoint:])
     sorted_vec = merge(left, right)
     return sorted_vec
