#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr int kMaxN = 10'000;

struct Set {
  int weight;
  std::vector<int> nodes;
};

int N;
std::vector<int> weights(kMaxN + 1);
std::vector<std::vector<int>> edges(kMaxN + 1, std::vector<int>());
std::vector<std::vector<Set>> dp_table(kMaxN + 1, std::vector<Set>(2, {-1}));

Set dp(int root, int parent, bool include);

void concat_vector(std::vector<int>* left, const std::vector<int>& right) {
  left->insert(left->end(), right.begin(), right.end());
}

Set get_include(int root, int parent) {
  int sum = weights[root];
  std::vector<int> nodes{root};

  for(const auto& child : edges[root]) {
    if(child == parent)
      continue;
    const auto dp_result = dp(child, root, false);
    sum += dp_result.weight;
    concat_vector(&nodes, dp_result.nodes);
  }
  return {sum, nodes};
}

Set get_exclude(int root, int parent) {
  int sum = 0;
  std::vector<int> nodes;

  for(const auto& child : edges[root]) {
    if(child == parent)
      continue;
    const auto dp_result_include = dp(child, root, true);
    const auto dp_result_exclude = dp(child, root, false);
    if(dp_result_include.weight < dp_result_exclude.weight) {
      sum += dp_result_exclude.weight;
      concat_vector(&nodes, dp_result_exclude.nodes);
    } else {
      sum += dp_result_include.weight;
      concat_vector(&nodes, dp_result_include.nodes);
    }
  }
  return {sum, nodes};
}

Set dp(int root, int parent, bool include) {
  auto& curr = dp_table[root][include];
  if(curr.weight != -1)
    return curr;

  if(include)
    return curr = get_include(root, parent);
  return curr = get_exclude(root, parent);  
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    std::cin >> weights[i];

  int from, to;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }

  const auto root_include = dp(1, -1, true);
  const auto root_exclude = dp(1, -1, false);

  auto ans = root_include.weight < root_exclude.weight ? root_exclude : root_include;

  std::cout << ans.weight << std::endl;
  std::sort(ans.nodes.begin(), ans.nodes.end());
  for(const auto& elem : ans.nodes)
    std::cout << elem << ' ';
}
