#include <iostream>
#include <sstream>
#include <string>

std::string encode(std::string s) {
  std::stringstream ss;
  char cur;
  int count = 1;
  for (int i = 0; i < s.size(); i++) {
    cur = s[i];
    while (i < s.size() - 1 && s[i+1] == cur) {
      count++;
      i++;
    }
    if (count > 1) {
      ss << count;
    }
    ss << cur;
    count = 1;
  }
  return ss.str();
}

int main() {
  for (std::string line; std::getline(std::cin, line);) {
    std::cout << encode(line) << std::endl;
  }
  return 0;
}
