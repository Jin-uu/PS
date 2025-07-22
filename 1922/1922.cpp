#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

constexpr int kMaxN = 1'000;
constexpr int kMaxM = 100'000;
constexpr int kMaxWeight = 10'000;

struct Edge {
  int u;
  int v;
  int weight;
};

int N, M;
std::vector<Edge> edges;
std::vector<int> roots;
std::vector<int> union_size;

void init() {
  edges.resize(M);
  roots.resize(N + 1);
  std::iota(roots.begin(), roots.end(), 0);
  union_size.resize(N + 1);
  std::fill(union_size.begin(), union_size.end(), 1);
}

int find_root(int target) {
  int& root = roots[target];
  return root == target ? target : root = find_root(root);
}

bool merge_union(int u, int v) {
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

  std::cin >> N >> M;
  init();

  for(auto& elem : edges)
    std::cin >> elem.u >> elem.v >> elem.weight;

  std::sort(edges.begin(), edges.end(),
            [] (const Edge& left, const Edge& right) { return left.weight < right.weight; });

  int edge_count = 0;
  int sum = 0;

  for(const auto& edge : edges) {
    if(!merge_union(edge.u, edge.v))
      continue;
    
    edge_count++;
    sum += edge.weight;

    if(edge_count == N - 1)
      break;
  }
  std::cout << sum;
}
