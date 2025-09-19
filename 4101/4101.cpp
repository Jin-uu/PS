#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int left, right;
  for(;;) {
    std::cin >> left >> right;
    if(left == 0 && right == 0)
      break;
    
    if(left > right)
      std::cout << "Yes" << '\n';
    else
      std::cout << "No" << '\n';
  }
}