#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>

constexpr int kMaxN = 100;
constexpr int kMaxM = 100;

struct Edge {
  int u;
  int v;
  int dist;
};

struct Location {
  int x;
  int y;
  int id;
};

struct Direction {
  int x;
  int y;
};

int N, M;

std::vector<std::vector<int>> map (kMaxM, std::vector<int>(kMaxN, -1));
std::vector<std::vector<int>> island (kMaxM, std::vector<int>(kMaxN, -1));
std::vector<Edge> edges;
std::vector<int> roots;
std::vector<int> union_size;
std::vector<Direction> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   // left, right, top, bottom

bool is_valid_location(const Location& loc) {
  return loc.x >= 0 && loc.x < M && loc.y >= 0 && loc.y < N;
}

int& get_island_with_loc(const Location& loc) {
  return island[loc.y][loc.x];
}

int& get_map_with_loc(const Location& loc) {
  return map[loc.y][loc.x];
}

Location move(const Location& curr, const Direction& dir) {
  Location ret = curr;
  ret.x += dir.x;
  ret.y += dir.y;
  return ret;
}

int get_dist(const Location& u, const Location& v, const Direction& dir) {
  if(dir.x == 0)
    return std::abs(u.y - v.y) - 1;
  return std::abs(u.x - v.x) - 1;
}

void dfs(const Location& loc) {
  auto& curr_island = get_island_with_loc(loc);
  curr_island = loc.id;

  for(const auto& dir : directions) {
    Location next = move(loc, dir);
    if(is_valid_location(next) && get_map_with_loc(next) == 1 && get_island_with_loc(next) == -1)
      dfs(next);
  }
}

int set_island() {
  int curr_id = 1;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(map[i][j] == 1 && island[i][j] == -1) {
        dfs({j, i, curr_id});
        curr_id++;
      }
    }
  }
  return curr_id - 1;
}

void try_make_bridge(const Location& loc, const Direction& dir) {
  auto next_loc = loc;
  do {
    next_loc = move(next_loc, dir);
    if(!is_valid_location(next_loc) || get_island_with_loc(next_loc) == loc.id)
      return;
    if(get_island_with_loc(next_loc) != -1)
      break;
  } while(1);

  const auto dist = get_dist(loc, next_loc, dir);
  if(dist <= 1)
    return;
  
  const int v_id = get_island_with_loc(next_loc);
  edges.push_back({loc.id, v_id, get_dist(loc, next_loc, dir)});
}

void make_edges_unique() {
  std::map<std::pair<int, int>, int> edge_map;

  for (const auto& e : edges) {
    int a = std::min(e.u, e.v);
    int b = std::max(e.u, e.v);
    auto& ref = edge_map[{a, b}];
    if (ref == 0 || e.dist < ref) {
        ref = e.dist;
    }
  }

  edges.clear();
  for (const auto& [p, d] : edge_map) {
    edges.push_back({p.first, p.second, d});
  }
}

void set_edges() {
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      const Location& curr_loc = {j, i, island[i][j]};
      const auto& map_value = get_map_with_loc(curr_loc);
      if(map_value == 0)
        continue;
      for(const auto& dir : directions) {
        try_make_bridge(curr_loc, dir);
      }
    }
  }
  make_edges_unique();
  std::sort(edges.begin(), edges.end(), [] (const Edge& left, const Edge& right) { return left.dist < right.dist; });
}

void init(int island_count) {
  roots.resize(island_count + 1);
  std::iota(roots.begin(), roots.end(), 0);
  union_size.resize(island_count + 1);
  std::fill(union_size.begin(), union_size.end(), 1);
}

int find_root(int target) {
  auto& root = roots[target];
  return root == target ? target : root = find_root(root);
}

bool concat_union(const int u, const int v) {
  auto root_u = find_root(u);
  auto root_v = find_root(v);
  
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
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      std::cin >> map[i][j];
    }
  }

  const int island_num = set_island();
  init(island_num);

  set_edges();

  int bridge_count = 0;
  int sum = 0;
  for(const auto& edge : edges) {
    if(!concat_union(edge.u, edge.v))
      continue;
    bridge_count++;
    sum += edge.dist;

    if(bridge_count == island_num -1)
      break;
  }

  if(bridge_count != island_num - 1)
    std::cout << -1;
  else
    std::cout << sum;
}
