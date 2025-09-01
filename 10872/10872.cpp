#include <iostream>

int main(void) {
  int N;
  std::cin >> N;

  int ans = 1;
  for(int i = N; i > 1; --i)
    ans *= i;

  std::cout << ans;
}
