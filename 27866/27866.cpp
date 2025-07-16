#include <iostream>
#include <string>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  std::string str;
  int n;
  std::cin >> str >> n;

  std::cout << str.at(n-1);
}
