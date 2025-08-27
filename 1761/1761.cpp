#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int kMaxN = 40'000;

struct Edge {
  int to;
  int weight;
};

int N, M, log_bound = 1;
std::vector<std::vector<Edge>> tree(kMaxN + 1);
std::vector<int> node_depth(kMaxN + 1, -1);   // depth from root
std::vector<int> root_dist(kMaxN + 1, 0);     // dist from root
std::vector<std::vector<int>> up_table(kMaxN + 1, std::vector<int>(17, 0));   // up_table[n][k] = n's upper 2^k parent node

void get_node_input() {
  int from, to, weight;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> from >> to >> weight;
    tree[from].push_back({to, weight});
    tree[to].push_back({from, weight});
  }
}

// return depth'th parent node
int lift(const int target, const int depth) {
  int ret = target;
  for (int i = 0; i < log_bound; ++i) {
    if (depth & (1 << i))
      ret = up_table[ret][i];
    if (ret == 0) break;
  }
  return ret;
}

int get_least_parent(int left, int right) {
  // right node should be deeper
  if(node_depth[left] > node_depth[right])
    std::swap(left, right);

  // lift deeper node to the other node's depth
  const int depth_diff = node_depth[right] - node_depth[left];
  int mid_node = lift(right, depth_diff);
  if(left == mid_node)
    return left;
  
  for(int i = log_bound - 1; i >= 0; --i) {
    if(up_table[left][i] != up_table[mid_node][i]) {
      left = up_table[left][i];
      mid_node = up_table[mid_node][i];
    }
  }
  return up_table[left][0];
}

void preprocess_tree() {
  const int root = 1;
  std::queue<int> q;
  q.push(1);
  node_depth[1] = 0;
  root_dist[1] = 0;
  up_table[1][0] = 0;

  while(!q.empty()) {
    const int curr = q.front();
    q.pop();

    for(const auto& edge : tree[curr]) {
      const auto& to = edge.to;
      if(node_depth[to] != -1)
        continue;
      q.push(to);
      node_depth[to] = node_depth[curr] + 1;
      root_dist[to] = root_dist[curr] + edge.weight;
      up_table[to][0] = curr;
    }
  }

  while ((1 << log_bound) <= N) ++log_bound;
  for(int i = 1; i < log_bound; ++i) {
    for(int j = 1; j <= N; ++j) {
      up_table[j][i] = up_table[up_table[j][i - 1]][i - 1];
    }
  }
}

int solve() {
  int from, to;
  std::cin >> from >> to;

  const int least_parent = get_least_parent(from, to);
  return root_dist[from] + root_dist[to] - root_dist[least_parent] * 2;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  get_node_input();
  preprocess_tree();

  std::cin >> M;
  for(int i = 0; i < M; ++i)
    std::cout << solve() << std::endl;
}
