#include <iostream>
#include <vector>
#include <unordered_map>

constexpr int kMaxN = 300'000;

using ll = long long;

struct Edge {
  int to;
  int weight;
};

struct Value {
  ll weight_sum;
  int node_count;
};

int N;
std::vector<std::vector<Edge>> edges(kMaxN + 1, std::vector<Edge>());
std::vector<std::unordered_map<int, Value>> dp_table(kMaxN + 1);

void get_input() {
  std::cin >> N;
  
  int from, to, weight;
  for (int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to >> weight;
    edges[from].push_back({to, weight});
    edges[to].push_back({from, weight});
  }
}

Value dp(int root, int parent) {
  if(dp_table[parent].find(root) != dp_table[parent].end())
   return dp_table[parent].at(root);

  ll sum = 0;
  int size = 1;
  if(root == 6 && parent == 1)
    int a = 1;
  if(root == 2 && parent == 1)
    int a = 1;
  for(const auto& edge : edges[root]) {
    if(edge.to == parent)
      continue;
    const auto value = dp(edge.to, root);
    sum += edge.weight * value.node_count;
    sum += value.weight_sum;
    size += value.node_count;
  }
  dp_table[parent].insert({root, {sum, size}});

  return {sum, size};
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  get_input();
  for(int i = 1; i <= N; ++i)
   std::cout << dp(i, 0).weight_sum << '\n';
}

