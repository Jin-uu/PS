#include <iostream>
#include <vector>

constexpr int kMax = 1'000;

int N;
std::vector<int> is_prime(kMax + 1, true);

void init() {
  is_prime[0] = false;
  is_prime[1] = false;

  for(int i = 2; i <= kMax; ++i) {
    if(is_prime[i])
      for(int j = i + i; j <= kMax; j += i)
        is_prime[j] = false;
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  init();

  int in;
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    std::cin >> in;
    if(is_prime[in])
      ans++;
  }
  std::cout << ans;
}

