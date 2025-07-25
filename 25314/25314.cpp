#include <iostream>

int N;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N;
  for(int i = 0; i < N / 4; ++i)
    std::cout << "long ";
  std::cout << "int";
}
