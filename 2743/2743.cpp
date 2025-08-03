#include <iostream>
#include <string>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::string in;
  std::cin >> in;

  std::cout << in.size();
}
