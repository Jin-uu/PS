#include <iostream>

void solve() {
  int n;
  std::cin >> n;
  if((n + 1) % (n % 100) == 0)
    std::cout << "Good" << std::endl;
  else
    std::cout << "Bye" << std::endl;
  
}

int main(void) {
  int T;
  std::cin >> T;
  for(int i = 0; i < T; ++i)
    solve();
}
