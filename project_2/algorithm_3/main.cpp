#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void print_vec(std::vector<int> &v){
  std::stringstream ss;
  ss << "[";
  for (int n: v) {
    ss << n;
    ss << ",";
  }
  std::string s = ss.str();
  s[s.size() - 1] = ']';
  std::cout << s << std::endl;
}

std::vector<std::vector<int>> parse() {
  bool in_array = false;
  std::vector<std::vector<int>> nums;
  for (std::string line; std::getline(std::cin, line);) {
    if (line[0] == 'A') {
      in_array = true;
      std::vector<int> v;
      nums.push_back(v);
    } else if (line.size() == 0) {
      in_array = false;
    }
    if (in_array) {
      int i = 0;
      // advance past first bracket
      while (i < line.size() && line[i] != '[')
        i++;
      // read all numbers (and signs) between the brackets
      while (i < line.size() && line[i] != ']') {
        int start = -1;
        int end = -1;
        while (isdigit(line[i]) || line[i] == '-') {
          if (start == -1) {
            start = i;
            end = i;
          } else
            end = i;
          i++;
        }
        i++;
        if (start > -1 && end > -1)
          nums[nums.size() - 1].push_back(
              std::stoi(line.substr(start, end - start + 1)));
      }
    }
  }
  return nums;
}

int partition(int i, int j, std::vector<int> &v) {
  int pivot_element = v[i]; 
  int start = i;
  int end = j ;
  while (true) {
    while (v[end] > pivot_element) end--;
    while (v[start] < pivot_element) start++;
    if (start < end){
      std::iter_swap(v.begin() + start, v.begin() + end);
      start++;
      end--;
    } else return start;
  }
}


void quick_sort(int i, int j, std::vector<int> &v) {
  if (i < j){
    int partition_index = partition(i, j, v);
    quick_sort(i, partition_index, v);
    quick_sort(partition_index + 1, j, v);
  }
}

int main() {
  std::vector<std::vector<int>> p = parse();
  for (std::vector<int> parsed_input: p){
    quick_sort(0, parsed_input.size() - 1, parsed_input);
    print_vec(parsed_input);
  }
  return 0;
}

