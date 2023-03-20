#include <iostream>
#include <sstream>
#include <string>

std::string encode(std::string s) {
// use a stringstream to prevent memory resizing 
// involved in string concatenations
  std::stringstream ss;
  // reference to the current character;
  char cur;
  // total of the current. always >= 1
  int count = 1;
  for (int i = 0; i < s.size(); i++) {
    // cur is the current character
    cur = s[i];
    // advance until the next character no longer matches cur
    while (i < s.size() - 1 && s[i+1] == cur) {
      count++;
      i++;
    }
    // if count > 1, there are multiple of the current string so we add that value
    if (count > 1) {
      ss << count;
    }
    // then we add the character
    ss << cur;
    // reset the count
    count = 1;
  }
  // retrun a string with the contents of the stringstream
  return ss.str();
}

int main() {
  // call encode on each string and print result
  for (std::string line; std::getline(std::cin, line);) {
    std::cout << encode(line) << std::endl;
  }
  return 0;
}
