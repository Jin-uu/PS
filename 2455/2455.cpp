#include <iostream>
#include <cmath>

int main(void) {
  int a, b;
  int curr = 0, ans = 0;
  for(int i = 0; i < 4; ++i) {
    std::cin >> a >> b;
    curr = curr - a + b;
    ans = std::max(ans, curr);
  }
  std::cout << ans;
}
