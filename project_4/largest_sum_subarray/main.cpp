#include <vector>
#include <assert.h>
#include <iostream>
#include <utility>
#include <string>
#include <cctype>

std::vector<std::vector<int>> parse() {
  std::vector<std::vector<int>> data;
  for (std::string line; std::getline(std::cin, line);) {
    std::vector<int> row;
    int start = 0;
    int end;
    while (start < line.size()) {
      end = start+1;
      while (end < line.size() && line[end] != ' ') {
        end++;
      }
      row.push_back(std::stoi(line.substr(start, end-start+1)));
      start = end+1;
      while (start < line.size() && line[start] == ' ') {
        start++;
      }
    }
    data.push_back(row);
  }
  return data;
}

/**
 * Largest Sum Subarray:
 * @params: std::vector<int>
 * @retruns: int e, int b, where the slice vector[b:e] has maximum sum
 */

std::pair<int, int> largest_sum_subarray(std::vector<int> &array) {
  int b, e;
  int max_sum = array[0];
  // iterate starting point from 0 to N-1
  for (int i = 0; i < array.size() - 1; i++) {
    int sum = array[i];
    if (sum > max_sum) {
      max_sum = sum;
      b=i;
      e=i+1;
    }
    // creates all subarrays starting a
    // running sum from the first element
    // & replaces max_sum if sum is greater
    for (int j = 1; j < array.size(); j++) {
      sum += array[j];
      if (sum > max_sum) {
        max_sum = sum;
        b=i;
        e=j+1;
      }
    }
  }
  // lower and upper bound of max sum slice
  return std::make_pair(b, e);
}

int main(){
  // test the function against the sample
  std::vector<int> sample_in = {-3, -5, 5, -1, -3, 1, 5, -6};
  auto sample_out = largest_sum_subarray(sample_in);
  std::pair<int, int> expected = std::make_pair(2, 7);
  assert(sample_out == expected);
  // run the algorithm against all parsed lists
  auto lists = parse();
  for (auto list: lists){
    for (int i: list){
      std::cout<< i << " ";
    }
    std::cout<<"\n";
    auto p = largest_sum_subarray(list);
    std::cout<< p.first << " " << p.second << "\n";
  }

  return 0;
}

