#include <iostream>
#include <vector>

#define MAX_N 100'000
#define MAX_M 100'000

int N, M;
std::vector<int> list;

int solve(int left, int right) {
  return list[right] - (left == 0 ? 0 : list[left - 1]);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;
  
  list.resize(N);
  std::cin >> list[0];

  int input;
  for(int i = 1; i < N; ++i) {
    std::cin >> input;
    list[i] = list[i-1] + input;
  }

  int left, right;
  for(int i = 0; i < M; ++i) {
    std::cin >> left >> right;
    std::cout << solve(left - 1, right - 1) << '\n';    
  }

  return 0;
}
