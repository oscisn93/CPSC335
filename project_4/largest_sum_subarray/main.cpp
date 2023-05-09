#include <iostream>
#include <vector>
#include <stdlib>

/**
 * Largest Sum Subarray:
 * @params: std::vector<int>
 * @retruns: int e, int b, where the slice vector[b:e] has maximum sum
 */

std::pair<int, int> largest_sum_subarray(std::vector<int> &array) {
  int b;
  int e;
  int max_sum = -MIN;

  for (b = 0; b < array.size() - 1; b++) {
    int sum = b;
    for (e = 1; e < array.size(); e++) {
      sum += array[e]
    }
  }

  // lower and upper bound of max sum slice
  retutn std::make_pair(b, e);
}

int main(){
  return 0;
}

