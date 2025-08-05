#include <iostream>
#include <string>
#include <sstream>

constexpr int kMaxStringLength = 1'000'000;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string in;
  std::getline(std::cin, in);

  std::istringstream iss(in);
  std::string temp;

  int word_count = 0;
  while (iss >> temp)
    word_count++;
    
  std::cout << word_count;
}
