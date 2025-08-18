#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using ll = long long;

int N, M, K;
std::vector<int> roots;
std::vector<int> sum;
std::vector<int> unions_sum;
std::vector<int> cnt;
std::vector<int> unions_cnt;

void init() {
  roots.resize(N + 1);
  std::iota(roots.begin(), roots.end(), 0);
  sum.resize(N + 1);
  cnt.resize(N + 1);
  std::fill(cnt.begin(), cnt.end(), 1);
}

int FindRoot(const int target) {
  auto& root = roots[target];
  if(target == root)
    return target;
  return root = FindRoot(root);
}

bool ConcatUnion(const int left, const int right) {
  int left_root = FindRoot(left);
  int right_root = FindRoot(right);

  if (left_root == right_root)
    return false;
  if (cnt[left_root] < cnt[right_root])
    std::swap(left_root, right_root);
  roots[right_root] = left_root;
  sum[left_root] += sum[right_root];
  cnt[left_root] += cnt[right_root];
  return true;
}

void GetCandyInput() {
  for(int i = 1; i <= N; ++i)
    std::cin >> sum[i];
}

void GetRelationInput() {
  int from, to;
  for(int i = 0; i < M; ++i) {
    std::cin >> from >> to;
    ConcatUnion(from, to);
  }
}

void FindUnionSum() {
  for(int i = 1; i <= N; ++i) {
    if(FindRoot(i) == i) {
      unions_sum.push_back(sum[i]);      
      unions_cnt.push_back(cnt[i]);
    }
  }
}

int solve() {
  int bound = K - 1;

  if (bound <= 0)
    return 0;

  std::vector<int> dp(bound + 1, 0);

  for (int i = 0; i < unions_sum.size(); ++i) {
    const int& curr_cnt    = unions_cnt[i];
    const int& curr_weight = unions_sum[i];

    for (int c = bound; c >= curr_cnt; --c)
      dp[c] = std::max(dp[c], dp[c - curr_cnt] + curr_weight);
  }
  return dp[bound];
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M >> K;
  init();

  GetCandyInput();
  GetRelationInput();
  FindUnionSum();

  std::cout << solve();
}

