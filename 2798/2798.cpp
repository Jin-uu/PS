#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100
#define MAX_M 300'000

int N, M, ans = -1;
std::vector<int> deck;

void solve(std::size_t index, int count, int sum) {
  if(count == 3 && sum <= M) {
    ans = std::max(ans, sum);
    return;
  }
  if(sum > M || index == deck.size())
    return;

  const int curr_card = deck[index];

  solve(index + 1, count + 1, sum + curr_card);
  solve(index + 1, count, sum);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;
  deck.resize(N);
  for(auto& elem : deck)
    std::cin >> elem;
  
  std::sort(deck.begin(), deck.end(), [](const int left, const int right) { return left > right; });

  int sum = 0;
  solve(0, 0, 0);
  std::cout << ans;
}
