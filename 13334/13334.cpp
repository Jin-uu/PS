#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <algorithm>
#include <functional>

using ll = long long;

struct Segment {
  ll left;
  ll right;
};

int N, D;
std::vector<Segment> segs;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    ll h, o;
    std::cin >> h >> o;

    const ll left = std::min(h, o);
    const ll right = std::max(h, o);
    segs.push_back({left, right});
  }

  std::cin >> D;

  std::vector<Segment> filtered;

  for (const auto& elem : segs) {
    const ll& l = elem.left;
    const ll& r = elem.right;
    if (r - l <= D)
      filtered.push_back({l, r});
  }

  std::sort(filtered.begin(), filtered.end(), [](const Segment& a, const Segment& b) {
    if (a.right != b.right)
      return a.right < b.right;
    return a.left < b.left;
  });
  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;

  int ans = 0;
  for (const auto& elem : filtered) {
    const ll& right = elem.right;
    const ll& left = elem.left;
    pq.push(left);

    while (!pq.empty() && pq.top() < right - D)
      pq.pop();

    ans = std::max(ans, static_cast<int>(pq.size()));
  }

  std::cout << ans << '\n';
  return 0;
}