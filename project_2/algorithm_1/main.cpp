#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>

int substring_index(std::string text, std::string pattern) {
  for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
    std::string slice = text.substr(i, pattern.size());
    if (slice == pattern)
      return i;
  }
  return -1;
}

#define input_data                                                             \
  std::pair<std::vector<std::string>, std::vector<std::map<int, std::string>>>

input_data parse() {
  std::vector<std::string> inputs;
  std::vector<std::map<int, std::string>> patterns;
  bool is_pattern = false;

  for (std::string line; std::getline(std::cin, line);) {
      if (line[0] == 'a') {
        int start = 0;
        int end;
        while (line[start] != '[')
          start++;
        while (!std::isalpha(line[start]))
          start++;
        end = start;
        if (!is_pattern) {
          while (std::isalpha(line[end]))
            end++;
          inputs.push_back(line.substr(start, end - start));
          patterns.push_back(std::map<int, std::string>());
          is_pattern = true;
        } else {
          while (line[end] != ']') {
            while (!std::isalpha(line[end]))
              end++;
            if (end > line.size())
              break;
            start = end;
            while (line[end] != ']' && std::isalpha(line[end]))
              end++;
            if (line[end] != ']') {
              int last_index = inputs.size() - 1;
              std::string search_string = inputs[inputs.size() - 1];
              std::string pattern = line.substr(start, end - start);
              int position = substring_index(search_string, pattern);
              patterns[last_index][position] = pattern;
            }
          }
          is_pattern = false;
        }
    }
  }
  return std::make_pair(inputs, patterns);
}

int main() {
  input_data d = parse();
  for (int i = 0; i < d.first.size(); i++) {
    std::string order = "Output_order = [";
    std::string cities = "Output_array = [";
    for (auto p : d.second[i]) {
      order += ("" + std::to_string(p.first) + ",");
      cities += ("\'" + p.second + "\',");
    }
    order[order.size() - 1] = ']';
    cities[cities.size() - 1] = ']';
    std::cout << order << "\n" << cities << std::endl;
  }
  return 0;
}
   
