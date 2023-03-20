#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>

// returns the index of the substring in the pattern if it exists
int substring_index(std::string text, std::string pattern) {
  // iterate n times where n is the number of pattern sized substrings
  for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
    // reduce compares by only comparing the strings
    // that start with the same character
    if (text[i] == pattern[0]) {
      // create a slice and compare the two strings
      std::string slice = text.substr(i, pattern.size());
      // return index once we find the first match
      if (slice == pattern)
        return i;
    }
  }
  // in case no matches
  return -1;
}

auto parse() {
  // an array for the search_strings
  std::vector<std::string> inputs;
  // an ordered map of indexs and patterns
  std::vector<std::map<int, std::string>> patterns;
  // a flag that tells us when toatart parsing a new problem input
  bool is_pattern = false;
  // read directly from standard input
  for (std::string line; std::getline(std::cin, line);) {
    
    if (line[0] == 'a') {
      // we start a new array everytime we 
      // encounter a line that starts with 'a'
      int start = 0;
      int end;
      // advance past first opening bracket
      while (line[start] != '[')
        start++;
      // advance again past quotes, spaces, and double quotes
      while (!std::isalpha(line[start]))
        start++;
      // now set end
      end = start;
      if (!is_pattern) {
        // parse first array as an input
        while (std::isalpha(line[end]))
          end++;
        inputs.push_back(line.substr(start, end - start));
        patterns.push_back(std::map<int, std::string>());
        // set mode to pattern
        is_pattern = true;
      } else {
        // pattern parsing mode
        while (line[end] != ']') {
          // again ignore non alphabetical characters
          while (!std::isalpha(line[end]))
            end++;
          // bounds check
          if (end > line.size())
            break;
          // if end is in bounds set it as the start of the next word
          start = end;
          while (line[end] != ']' && std::isalpha(line[end]))
            end++;
          // once end is calculated push the substing between
          // find the index of the substring from start to end 
          // and set the value of the pattern map at that position 
          // as the key for the value of the pattern
          if (line[end] != ']') {
            int last_index = inputs.size() - 1;
            std::string search_string = inputs[last_index];
            std::string pattern = line.substr(start, end - start);
            int position = substring_index(search_string, pattern);
            patterns[last_index][position] = pattern;
          }
        }
        // flip back to parse the next problem input
        is_pattern = false;
      }
    }
  }
  return std::make_pair(inputs, patterns);
}

int main() {
  // d is  a pair of searchstrings and pattern maps
  auto d = parse();
  // for every search string create a string of
  // pattern indices, then add the search string 
  // to its own output string, in order
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
