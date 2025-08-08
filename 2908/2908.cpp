#include <iostream>
#include <string>
#include <algorithm>

int main(void) {
  std::string left, right;
  std::cin >> left >> right;

  std::reverse(left.begin(), left.end());
  std::reverse(right.begin(), right.end());

  std::cout << (left < right ? right : left);
}
