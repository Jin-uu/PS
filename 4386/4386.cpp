#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

struct Star {
  Star(const float x, const float y) : x(x), y(y) {}
  float x;
  float y;
};

struct Edge {
  Edge(const int u, const int v, const float dist) : u(u), v(v), dist(dist) {}
  int u;
  int v;
  float dist;
};

int N;
std::vector<Star> stars;
std::vector<Edge> edges;
std::vector<int> union_size;
std::vector<int> roots;

void init() {
  union_size.resize(N + 1);
  std::fill(union_size.begin(), union_size.end(), 1);
  roots.resize(N + 1);
  std::iota(roots.begin(), roots.end(), 0);
}

float get_dist(const Star& u, const Star& v) {
  const float x_diff = u.x - v.x;
  const float y_diff = u.y - v.y;
  return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

int find_root(int target) {
  int& root = roots[target];
  return target == root ? target : root = find_root(root);
}

bool merge_union(int u, int v) {
  int root_u = find_root(u);
  int root_v = find_root(v);
  if(root_u == root_v)
    return false;
  
  if(union_size[root_u] < union_size[v])
    std::swap(root_u, root_v);

  roots[root_v] = root_u;
  union_size[root_u] += union_size[root_v];
  return true;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  init();
  float curr_x, curr_y;
  for(int i = 0; i < N; i++) {
    std::cin >> curr_x >> curr_y;
    stars.emplace_back(curr_x, curr_y);
    for(int j = 0; j < stars.size() - 1; ++j)
      edges.emplace_back(j, i, get_dist(stars[j], stars[i]));     
  }

  std::sort(edges.begin(), edges.end(), [] (const Edge& left, const Edge& right) { return left.dist < right.dist; });

  float dist_sum = 0;
  int edge_count = 0;
  for(const auto& edge : edges) {
    if(!merge_union(edge.u, edge.v))
      continue;
    
    dist_sum += edge.dist;
    edge_count++;
    if(edge_count == N -1)
      break;
  }

  std::cout << dist_sum;
}
