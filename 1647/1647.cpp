#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100'000
#define MAX_M 1'000'000
#define MAX_W 1'000

using ll = long long;

struct Edge {
  int u;
  int v;
  int weight;
};

int N, M;
std::vector<Edge> edges;
std::vector<int> roots;
std::vector<int> union_size;

int find_root(int target) {
  if(target == roots[target])
    return target;
  return roots[target] = find_root(roots[target]);
}

bool concat_root(int u, int v) {
  int root_u = find_root(u);
  int root_v = find_root(v);

  if(root_u == root_v)
    return false;

  if(union_size[root_u] < union_size[root_v])
    std::swap(root_u, root_v);

  roots[root_v] = root_u;
  union_size[root_u] += union_size[root_v];

  return true;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;
  edges.resize(M);
  for(auto& elem : edges)
    std::cin >> elem.u >> elem.v >> elem.weight;

  roots.resize(N + 1);
  union_size.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    roots[i] = i;
    union_size[i] = 1;
  }

  std::sort(edges.begin(), edges.end(), [] (const Edge& left, const Edge& right) { return left.weight < right.weight; });

  int curr_edge_count = 0;
  ll curr_edge_sum = 0;
  int last_edge_weight = -1;
  for(const auto& edge : edges) {
    if(!concat_root(edge.u, edge.v))
      continue;
    curr_edge_count++;
    curr_edge_sum += edge.weight;
    if(curr_edge_count == N -1) {
      last_edge_weight = edge.weight;
      break;
    }
  }
  std::cout << curr_edge_sum - last_edge_weight;
}

