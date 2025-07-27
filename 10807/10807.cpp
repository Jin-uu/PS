#include <iostream>
#include <vector>

constexpr int MAX_V = 100;

int N;

int get_index(int n) {
  return n + MAX_V;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  std::vector<int> vec(MAX_V * 2 + 2, 0);

  int in;
  for(int i = 0; i < N; ++i) {
    std::cin >> in;
    vec[get_index(in)]++;
  }

  int target;
  std::cin >> target;
  std::cout << vec[get_index(target)];
}
