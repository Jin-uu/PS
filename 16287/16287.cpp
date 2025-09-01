#include <iostream>
#include <vector>

constexpr int MAX_N = 5000;
constexpr int kMaxWeight = 400000;

int w, n;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> w >> n;

  std::vector<int> values(n);
  for (int i = 0; i < n; i++)
    std::cin >> values[i];

  std::vector<int> first_index(kMaxWeight + 1, -1);
  std::vector<int> second_index(kMaxWeight + 1, -1);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int pair_sum = values[i] + values[j];
      if (first_index[pair_sum] == -1) {
        first_index[pair_sum] = i;
        second_index[pair_sum] = j;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int need_sum = w - (values[i] + values[j]);

      if (need_sum < 0 || need_sum > kMaxWeight) continue;
      if (first_index[need_sum] == -1) continue;

      int a = first_index[need_sum];
      int b = second_index[need_sum];
      if (a != i && a != j && b != i && b != j) {
        std::cout << "YES";
        return 0;
      }
    }
  }

  std::cout << "NO";
  return 0;
}