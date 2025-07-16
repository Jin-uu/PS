#include <iostream>
#include <string>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a + b - c << '\n';
  std::cout << std::stoi(std::to_string(a) + std::to_string(b)) - c << '\n';
}
