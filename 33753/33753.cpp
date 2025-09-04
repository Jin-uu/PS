#include <iostream>

int A, B, C, T;

int solve() {
  if(T <= 30)
  return A;
  
  int ret = A;
  int diff = T - 30;
  ret += diff / B * C;
  if(diff % B != 0)
    ret += C;
  return ret;
}

int main(void) {
  std::cin >> A >> B >> C >> T;
  std::cout << solve();
}
