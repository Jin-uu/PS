#include <iostream>
#include <string>

bool is_palindrome(const std::string& str) {
  const auto len = str.size();

  for(int i = 0; i < len / 2; ++i) {
    if(str[i] != str[len - i - 1])
      return false;
  }
  return true;
}

int main(void) {
  std::string in;
  std::cin >> in;

  std::cout << is_palindrome(in);
}
