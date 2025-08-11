#include <iostream>

void print_c_n(const int n, const char c) {
  for(int i = 0; i < n; ++i)
    std::cout << c;
}

void print_n(const int n, const int blank) {
  print_c_n(blank, ' ');
  print_c_n(n, '*');
  std::cout << '\n';
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    print_n(i * 2 - 1, N - i);
  for(int i = N-1; i > 0; --i)
    print_n(i * 2 - 1, N - i);
}
