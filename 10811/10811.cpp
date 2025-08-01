#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int N, M;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  std::vector<int> vec(N + 1);
  std::iota(vec.begin(), vec.end(), 0);

  int left, right;
  for(int i = 0; i < M; ++i) {
    std::cin >> left >> right;
    std::reverse(vec.begin() + left, vec.begin() + right + 1);
  }

  for(int i = 1; i < vec.size(); ++i)
    std::cout << vec[i] << ' ';
}
