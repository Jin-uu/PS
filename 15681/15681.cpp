#include <iostream>
#include <vector>

constexpr int kMaxN = 100'000;

int N, R, Q;

std::vector<std::vector<int>> edges(kMaxN + 1, std::vector<int>());
std::vector<int> dp_table(kMaxN + 1, -1);
std::vector<int> is_visited(kMaxN + 1, false);

void get_edges() {
  int from, to;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }
}

int solve(int root) {
  is_visited[root] = true;
  int& curr = dp_table[root];

  if(curr != -1)
    return curr;

  if(edges[root].empty())
    return curr = 1;

  int sum = 0;
  for(const auto& elem : edges[root]) {
    if(!is_visited[elem])
      sum += solve(elem);
  }

  return curr = sum + 1;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> R >> Q;
  get_edges();

  solve(R);
  int target;
  for(int i = 0; i < Q; ++i){
    std::cin >> target;
    std::cout << solve(target) << '\n';
  }
}
