#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

auto parse_input() {
  std::vector<std::vector<int>> data;
  std::string line;

  for (int k = 0; k < 2; k++) {
    std::getline(std::cin, line);
    std::vector<int> values;

    int i = 0, start = -1, end = -1;

    while (i < line.size()) {
      while (line[i] == ' ' || line[i] == '\n') {
        i++;
      }
      start = i;
      while (std::isdigit(line[i])) {
        i++;
      }
      end = i;
      if (end > start) {
        values.push_back(stoi(line.substr(start, end)));
      }
      i++;
    }
    data.push_back(values);
  }

  int mpg;
  std::cin >> mpg;

  return std::make_pair(data, mpg);
}

int main(int argc, char const *argv[]) {
  std::cout << "args[" << argc << "] = ";
  std::cout << "[" << argv[0] << "]\n";
  auto data = parse_input();
  auto arrays = data.first;
  for (auto vec : arrays) {
    std::cout << "[";
    for (int value : vec) {
      std::cout << value << " ";
    }
    std::cout << "]\n";
  }
  std::cout << "mpg: " << data.second << "\n";
  return 0;
}
