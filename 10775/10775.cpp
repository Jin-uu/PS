#include <iostream>
#include <vector>
#include <numeric>

constexpr int kMaxGate = 100'000;
constexpr int kMaxPlain = 100'000;

int G, P;
int ans = 0;
std::vector<int> dest(kMaxPlain + 1);
std::vector<int> parent(kMaxGate + 1);

int GetRoot(const int target) {
  if(parent[target] == target)
    return target;
  return parent[target] = GetRoot(parent[target]);
}

void ConcatUnion(const int left, const int right) {
  const int left_root = GetRoot(left);
  const int right_root = GetRoot(right);
  parent[left_root] = right_root;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::iota(parent.begin(), parent.end(), 0);

  std::cin >> G >> P;
  for(int i = 0; i < P; ++i)
    std::cin >> dest[i];

  for(int i = 0; i < P; ++i) {
    const auto& curr = dest[i];
    const auto target = GetRoot(curr);

    if(target == 0)
      break;

    ++ans;
    ConcatUnion(target, target - 1);
  }
  std::cout << ans;
}
