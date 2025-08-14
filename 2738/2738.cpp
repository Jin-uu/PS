#include <iostream>
#include <vector>

void get_input(std::vector<std::vector<int>>* vec, const int n, const int m) {
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      std::cin >> (*vec)[i][j];
}

void print_ans(const std::vector<std::vector<int>>& left, const std::vector<std::vector<int>>& right, const int n, const int m) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j)
      std::cout << left[i][j] + right[i][j] << ' ';
    std::cout << std::endl;
  }
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> a(N, std::vector<int>(M));
  std::vector<std::vector<int>> b(N, std::vector<int>(M));
  get_input(&a, N, M);
  get_input(&b, N, M);

  print_ans(a, b, N, M);
}
