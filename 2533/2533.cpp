#include <iostream>
#include <vector>
#include <algorithm>

constexpr int kMaxN = 1'000'000;

int N;
std::vector<std::vector<int>> tree(kMaxN + 1, std::vector<int>(0));
std::vector<std::vector<int>> dp_table(kMaxN + 1, std::vector<int>(2, -1));   // 0 : True / 1 : False

void dp(int root, int parent) {
  const int child_cnt = tree[root].size();

  if(child_cnt == 0) {
    dp_table[root][0] = 1;
    dp_table[root][1] = 0;
    return;
  }

  int true_sum = 0;
  int false_sum = 0;
  for(const auto& child : tree[root]) {
    if(child == parent)
      continue;
    dp(child, root);
    const auto& child_true = dp_table[child][0];
    const auto& child_false = dp_table[child][1];
    true_sum += std::min(child_true, child_false);
    false_sum += child_true;
  }
  dp_table[root][0] = true_sum + 1;
  dp_table[root][1] = false_sum;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  int from, to;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }
  dp(1, -1);
  std::cout << std::min(dp_table[1][0], dp_table[1][1]);
}
