#include <iostream>

using ll = long long;

constexpr int kDay = 24 * 60 * 60;

ll A, B, C, D;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> A >> B >> C >> D;

  const ll start = A * 60 * 60 + B * 60 + C;
  const ll end = (start + D) % kDay;

  std::cout << end / 3600 << ' ' << (end % 3600) / 60 << ' ' << end % 60;
}