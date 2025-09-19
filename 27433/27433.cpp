#include <iostream>

using ll = long long;

int main(void) {
  int in;
  std::cin >> in;
  
  ll ans = 1;
  while(in > 0) {
    ans *= in;
    --in;
  }
  std::cout << ans;
}
