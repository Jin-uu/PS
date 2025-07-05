#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100'000
#define MAX_M 100'000

int N, M;
std::vector<long long> targets, bullets;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  targets.resize(N);
  for(int i = 0; i < N; ++i)
    std::cin >> targets[i];
  
  std::cin >> M;
  bullets.resize(M);
  for(int i = 0; i < M; ++i)
    std::cin >> bullets[i];

  std::sort(targets.begin(), targets.end());
  
  for(const auto& elem : bullets) {
    const auto it = std::lower_bound(targets.begin(), targets.end(), elem);
    if(*it == elem)
      std::cout << 1 << '\n';
    else 
      std::cout << 0 << '\n';
  }
}

