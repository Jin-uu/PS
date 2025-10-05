#include <iostream>
#include <vector>
#include <cmath>

constexpr int kMaxN = 10'000;

int N;

std::vector<int> population(kMaxN + 1);
std::vector<std::vector<int>> edges(kMaxN + 1, std::vector<int>());
std::vector<std::vector<int>> dp_table(kMaxN + 1, std::vector<int>(2, -1));

int dp(int root, int parent, bool include);

int get_include(int root, int parent) {
  int sum = population[root];
  for(const auto& elem : edges[root]) {
    if(elem == parent)
      continue;
    sum += dp(elem, root, false);
  }
  return sum;
}

int get_exclude(int root, int parent) {
  int sum = 0;
  for(const auto& elem : edges[root]) {
    if(elem == parent)
      continue;
    sum += std::max(dp(elem, root, true), dp(elem, root, false));
  }
  return sum;
}

int dp(int root, int parent, bool include) {
  auto& curr = dp_table[root][include];
  if(curr != -1)
    return curr;

  if(include)
    return curr = get_include(root, parent);
  return curr = get_exclude(root, parent);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  int in;
  for(int i = 0; i < N; ++i) {
    std::cin >> in;
    population[i + 1] = in;
  }

  int from, to;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }

  std::cout << std::max(dp(1, -1, true), dp(1, -1, false));
}
