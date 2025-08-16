#include <iostream>

int main(void) {
  int ans = 0;
  
  int in;
  for(int i = 0; i < 5; ++i) {
    std::cin >> in;
    ans += in * in;
  }
  
  std::cout << ans % 10;
}
