#include <iostream>
#include <vector>

int N, M;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  std::vector<int> vec(N+1, 0);

  int a, b, c;
  for(int i = 0; i < M; i++) {
    std::cin >> a >> b >> c;
    for(int j = a; j <= b; ++j)
      vec[j] = c;
  }
  
  for(int i = 1; i <= N; i++)
    std::cout << vec[i] << ' ';
}
