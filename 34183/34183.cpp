#include <iostream>

int N, M, A, B;

int main(void) {
  std::cin >> N >> M >> A >> B;

  int ans = (N * 3 - M) * A;
  std::cout << ((ans <= 0) ? 0 : ans + B);
}
