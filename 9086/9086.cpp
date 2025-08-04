#include <iostream>
#include <string>

void solve() {
  std::string in;
  std::cin >> in;
  std::cout << in.front() << in.back() << std::endl;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for(int i = 0; i < T; ++i)
    solve();
}
