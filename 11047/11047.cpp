#include <iostream>
#include <vector>

#define MAX_N 10
#define MAX_K 100'000'000

int N, K;
std::vector<int> coins(MAX_N, -1);


int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  for(int i = 0; i < N; ++i)
    std::cin >> coins[i];

  int ret = 0;

  for(int i = N - 1; i >= 0; --i) {
    const auto curr_coin = coins[i];
    int count = K / curr_coin;
    ret += count;
    K -= count * curr_coin;
  }

  std::cout << ret;
}
