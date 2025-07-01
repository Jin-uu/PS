#include <iostream>
#include <vector>

#define MAX_N 100
#define MAX_K 100'000
#define MAX_W 100'000

struct elem {
  int weight = -1;
  int value = -1;
};

int N, K;
std::vector<elem> bag(MAX_N);
// dp_table[i][j] : i 인덱스 elem까지 고려, j의 무게를 썼음때 최대 가치
std::vector<std::vector<int>> dp_table(MAX_N + 1, std::vector<int>(MAX_K + 1, -1));  

int dp(int index, int weight) {
  if(index < 0 || weight <= 0)
    return 0;

  int& ret = dp_table[index][weight];
  if(ret != -1)
    return ret;

  const auto& curr_elem = bag[index];
  int yes = (curr_elem.weight > weight ? 0 : dp(index - 1, weight - curr_elem.weight) + curr_elem.value);
  int no = dp(index - 1, weight);

  ret = std::max(yes, no);

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;

  int w, v;
  for(int i = 0; i < N; ++i) {
    std::cin >> w >> v;
    bag[i] = {w, v};
  }

  std::cout << dp(N - 1, K);
}
