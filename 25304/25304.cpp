#include <iostream>

using ll = long long;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  ll X, N;
  std::cin >> X >> N;

  int a, b;
  ll sum = 0;
  for(int i = 0; i < N; ++i) {
    std::cin >> a >> b;
    sum += a * b;
  }
  if(sum == X)
    std::cout << "Yes";
  else
    std::cout << "No";
}
