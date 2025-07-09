#include <iostream>
#include <vector>
#include <limits>

#define MAX_N 500
#define MAX_B 64'000'000

int N, M, B;
std::vector<std::vector<int>> map(MAX_N + 1, std::vector<int>(MAX_N + 1, -1));

int get_block_plus(const int height) {
  int ret = 0, plus;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      const auto& curr = map[i][j];
      plus = curr - height;
      ret += plus <= 0 ? 0 : plus; 
    }
  }
  return ret;
}

int get_block_minus(const int height) {
  int ret = 0, minus;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      const auto& curr = map[i][j];
      minus = height - curr;
      ret += minus <= 0 ? 0 : minus;
    }
  }
  return ret;
}


int get_time(const int height) {
  int inven = B;
  const int plus = get_block_plus(height);
  const int minus = get_block_minus(height);
  inven += plus;

  if(inven < minus)
    return -1;
  return plus * 2 + minus;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> B;

  int min_height = std::numeric_limits<int>::max();
  int max_height = std::numeric_limits<int>::min();
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      std::cin >> map[i][j];
      min_height = std::min(min_height, map[i][j]);
      max_height = std::max(max_height, map[i][j]);
    }
  }

  int min_time = std::numeric_limits<int>::max();;
  int ans_height = -1;

  for(int i = min_height; i <= max_height; ++i) {
    const int time = get_time(i);
    if(time == -1 || min_time < time)
      continue;
    min_time = time;
    ans_height = i;
  }
  std::cout << min_time << ' ' << ans_height;
}
