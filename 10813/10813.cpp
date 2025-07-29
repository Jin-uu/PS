#include <iostream>
#include <vector>
#include <numeric>

int N, M;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::cin >> N >> M;

  std::vector<int> vec(N + 1);
  std::iota(vec.begin(), vec.end(), 0);

  int a, b;
  for(int i = 0; i < M; i++) {
    std::cin >> a >> b;
    std::swap(vec[a], vec[b]);
  }

  for(int i = 1; i < N+1; ++i)
    std::cout << vec[i] << ' ';
}
