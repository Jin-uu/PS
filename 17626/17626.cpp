#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define MAX_N 50'000
#define MAX_S 223
constexpr int kMaxInt = std::numeric_limits<int>::max();

int N;

std::vector<int> dp_table(MAX_N + 1, -1);

void init() {
  dp_table[0] = 0;
  for(int i = 1; i <= MAX_S; ++i)
    dp_table[i * i] = 1;
}

int dp(int curr) {
  int& ret = dp_table[curr];
  if(ret != -1)
    return ret;
  
  ret = kMaxInt;
  for(int i = 1; i * i <= curr; ++i)
    ret = std::min(ret, dp(curr - i * i) + 1);

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  init();

  std::cin >> N;
  std::cout << dp(N);
}
