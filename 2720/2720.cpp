#include <iostream>
#include <vector>

constexpr int kQuarter = 25;
constexpr int kDime = 10;
constexpr int kNickel = 5;
constexpr int kPenney = 1;

int T;

void solve() {
  int money;
  std::cin >> money;

  int q, d, n, p;
  q = money / kQuarter;
  money %= kQuarter;
  d = money / kDime;
  money %= kDime;
  n = money / kNickel;
  money %= kNickel;
  p = money / kPenney;

  std::cout << q << ' ' << d << ' ' << n << ' ' << p << std::endl;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> T;
  for(int i = 0; i < T; ++i)
    solve();
}


