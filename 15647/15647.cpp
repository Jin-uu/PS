#include <iostream>
#include <vector>

using ll = long long;

constexpr int kMaxN = 300'000;

struct Edge {
  int to;
  int weight;
};

int N;
std::vector<std::vector<Edge>> edges(kMaxN + 1);
std::vector<int> sub_tree_size(kMaxN + 1);
std::vector<ll> dp_table(kMaxN + 1, -1);
std::vector<ll> answer(kMaxN + 1);

void get_input() {
  std::cin >> N;
  int from, to, weight;
  for(int i = 0; i < N -1; ++i) {
    std::cin >> from >> to >> weight;
    edges[from].push_back({to, weight});
    edges[to].push_back({from, weight});
  }
}

void dp(int root, int parent) {
  dp_table[root] = 0;
  sub_tree_size[root] = 1;

  for(const auto& [to, weight] : edges[root]) {
    if(to == parent)
      continue;
    dp(to, root);
    dp_table[root] += dp_table[to] + weight * sub_tree_size[to];
    sub_tree_size[root] += sub_tree_size[to];
  }
}

void re_root(int root, int parent) {
  for(const auto& [to, weight] : edges[root]) {
    if(to == parent)
      continue;
    answer[to] = answer[root] + weight * (N - 2 * sub_tree_size[to]);
    re_root(to, root);
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  get_input();

  dp(1, 0);
  answer[1] = dp_table[1];
  re_root(1, 0);
  for(int i = 1; i <= N; ++i)
    std::cout << answer[i] << '\n';
}
