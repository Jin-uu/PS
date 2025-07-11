#include <iostream>

int N, K;

int fact_from_to(const int from, const int to) {
  int ret = 1;
  for(int i = from; i <= to; i++)
    ret *= i;
  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;
  
  std::cout << fact_from_to(N - K + 1, N) / fact_from_to(1, K);
}
