#include <iostream>
#include <cmath>

using ll = long long;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  ll N;
  std::cin >> N;

  ll dots = std::pow(2, N) + 1;
  ll ans = dots * dots;
  std::cout << ans;
}
