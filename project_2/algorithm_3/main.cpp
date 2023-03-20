#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<int>> input_parser() {
  // we use a flag to determine when it's time to
  // stop parsing the current array
  bool in_array = false;
  std::vector<std::vector<int>> _2d_array;
  // read directly from standard input
  for (std::string line; std::getline(std::cin, line);) {
    // set in array to true to parse the next array
    if (line[0] == 'A') {
      in_array = true;
      std::vector<int> v;
      _2d_array.push_back(v);
    } else if (line.size() == 0) {
      // set to false when the line is empty 
      // so we can create a new empty array
      in_array = false;
    }
    // parse the current array- we're just 
    // reading in numbers until the line ends
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
        // advance the pointer past the last character
        i++;
        // add the full number to the current array
        if (start > -1 && end > -1)
          _2d_array[_2d_array.size() - 1].push_back(
              std::stoi(line.substr(start, end - start + 1)));
      }
    }
  }
  return _2d_array;
}



static int partition(int i, int j, std::vector<int> &v) {
  // set the pivot to the leftmost element
  int pivot_element = v[i];
  int start = i;
  int end = j;
  while (true) {
    // advance backaeards past all elements larger than the pivot
    while (v[end] > pivot_element)
      end--;
      // advance forward past all elements smaller than the pivot
    while (v[start] < pivot_element)
      start++;
    // if there are still numbers in between, 
    // swap and repeat, until the subpartition is sorted
    if (start < end) {
      std::iter_swap(v.begin() + start, v.begin() + end);
      start++;
      end--;
      // otherwise retrun the new pivot
    } else
      return start;
  }
}

void quick_sort(int i, int j, std::vector<int> &v) {
  if (i < j) {
    // find a partition index and sort both halfs until i >= j
    int partition_index = partition(i, j, v);
    quick_sort(i, partition_index, v);
    quick_sort(partition_index + 1, j, v);
  }
}
// utility function to easily print vectors
void print_vec(std::vector<int> &v) {
  std::stringstream ss;
  ss << "[";
  for (int n : v) {
    ss << n;
    ss << ",";
  }
  std::string s = ss.str();
  s[s.size() - 1] = ']';
  std::cout << s << std::endl;
}

int main() {
  // parse, sort, print
  auto p = input_parser();
  for (auto input : p) {
    quick_sort(0, input.size() - 1, input);
    print_vec(input);
  }
  return 0;
}
